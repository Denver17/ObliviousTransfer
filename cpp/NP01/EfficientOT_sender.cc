
#include <NTL/ZZ.h>
#include <fstream>
#include <sstream>
#include <openssl/sha.h>
#include <iomanip>
#include "../CryptoTools/StringCharArray.h"
#include "../CryptoTools/RWfile.h"
#include "../CryptoTools/ZZCal.h"
#include "../CryptoTools/sha256.h"
#include <vector>

#include <iostream>
#include <memory>
#include <string>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"

#include <grpcpp/grpcpp.h>


#include "EfficientOT.grpc.pb.h"


ABSL_FLAG(std::string, target, "localhost:50051", "Server address");

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;
using grpc::Status;
using EfficientOT::OT;
using EfficientOT::Reply;
using EfficientOT::Param;
using EfficientOT::Request;
using EfficientOT::CipherText;

const long length = 2048;
const int N = 5;
NTL::ZZ p, g, r, g_r, R;
std::vector<NTL::ZZ> C(N), M(N);

NTL::ZZ stringToZZ(const std::string &str)
{
    NTL::ZZ number = NTL::conv<NTL::ZZ>(str[0]);
    long len = str.length();
    for(long i = 1; i < len; i++)
    {
        number *= 128;
        number += NTL::conv<NTL::ZZ>(str[i]);
    }

    return number;
}


class OTSender {
public:
    OTSender(std::shared_ptr<Channel> channel)
        : stub_(OT::NewStub(channel)) {}

    std::string RequestParam() {
        // 选定R
        NTL::RandomBnd(R, p);
        std::string strR = zToString(R);

        Request request;

        Param param;

        ClientContext context;

        request.set_r(strR);

        Status status = stub_->RequestParam(&context, request, &param);

        if (status.ok()) {
            return param.pk0();
        } else {
            std::cout << status.error_code() << ": " << status.error_message()
                    << std::endl;
            return "RPC failed";
        }
    }

    std::string SendCipherText(const std::string &strPK0) {
        ClientContext context;
        Reply reply;
        std::unique_ptr<ClientWriter<CipherText> > writer(
        stub_->SendCipherText(&context, &reply));

        // 计算PK0 ^ r
        NTL::ZZ PK0 = NTL::conv<NTL::ZZ>(strPK0.c_str());
        NTL::ZZ PK0_r = NTL::PowerMod(PK0, r, p);
        NTL::ZZ invPK0_r = NTL::InvMod(PK0_r, p);

        std::string strR = zToString(R);
        // 计算密文并发送
        for(int i = 0; i < N; i++) {
            std::string str;
            if(i != 0) {
                NTL::ZZ Ci_r = NTL::PowerMod(C[i], r, p);
                NTL::ZZ PKi_r = NTL::MulMod(Ci_r, invPK0_r, p);
                str = zToString(PKi_r) + strR + std::to_string(i);
            }
            else {
                str = zToString(PK0_r) + strR + std::to_string(i);
            }
            // 哈希
            std::string strh = sha256(str);
            // 哈希之后的结果通过特定方式转化为ZZ变量
            // NTL::ZZ h = NTL::conv<NTL::ZZ>(strh.c_str());
            NTL::ZZ h = stringToZZ(strh);

            // 与明文异或
            NTL::ZZ res = h ^ M[i];
            std::string strres = zToString(res);

            CipherText ciphertext;
            ciphertext.set_ct(strres);

            if (!writer->Write(ciphertext)) {
                // Broken stream.
                break;
            }
        }

        writer->WritesDone();
        Status status = writer->Finish();

        if (status.ok()) {
            return reply.message();
        } else {
            std::cout << status.error_code() << ": " << status.error_message()
                    << std::endl;
            return "RPC failed";
        }
    }

    
private:
    std::unique_ptr<OT::Stub> stub_;
};

int main(int argc, char** argv) {
    absl::ParseCommandLine(argc, argv);
    std::string target_str = absl::GetFlag(FLAGS_target);
    OTSender sender(
        grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));

    // 读取公共参数
    if(readFile(p, "../../param/ParamP.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }
    if(readFile(g, "../../param/ParamG.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }
   for(int i = 1; i < N; i++) {
        std::string path = "../../param/ParamC" + std::to_string(i) + ".txt";
        if(readFile(C[i], path) < 0) {
            std::cerr << "Unable to open file." << std::endl;
            return 0;
        }
    }
    if(readFile(r, "../../param/ParamR.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }
    if(readFile(g_r, "../../param/ParamG_R.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }

    // 随机生成明文
    for(int i = 0; i < N; i++) {
        NTL::RandomBnd(M[i], p);
        std::cout << M[i] << "\n";
    }

    // 接收选择方发送的PK0
    std::string strPK0 = sender.RequestParam();

    std::string ret = sender.SendCipherText(strPK0);

    return 0;
}
