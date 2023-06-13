
#include <NTL/ZZ.h>
#include <fstream>
#include <sstream>
#include <openssl/sha.h>
#include <iomanip>
#include "../CryptoTools/aes.h"
#include "../CryptoTools/sha256.h"
#include "../CryptoTools/RWfile.h"

#include <iostream>
#include <memory>
#include <string>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"

#include <grpcpp/grpcpp.h>

#ifdef BAZEL_BUILD
#include "examples/protos/SimplestOT.grpc.pb.h"
#else
#include "SimplestOT.grpc.pb.h"
#endif

ABSL_FLAG(std::string, target, "localhost:50051", "Server address");

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using SimplestOT::OT;
using SimplestOT::BReply;
using SimplestOT::ARequest;
using SimplestOT::CTRequest;
using SimplestOT::CTReply;

const long long length = 2048;
NTL::ZZ p, g, a, A, B;


class OTSender {
public:
    OTSender(std::shared_ptr<Channel> channel)
        : stub_(OT::NewStub(channel)) {}

    std::string SendA(const std::string& A) {
        ARequest request;
        request.set_a(A);

        BReply reply;

        ClientContext context;

        Status status = stub_->SendA(&context, request, &reply);

        if (status.ok()) {
            return reply.b();
        } else {
            std::cout << status.error_code() << ": " << status.error_message()
                    << std::endl;
            return "RPC failed";
        }
    }

    std::string SendCipherText(const std::string& ciphertext) {
        CTRequest request;
        unsigned char c[(int)ciphertext.size()];
        stringToUnsignedCharArray(ciphertext, c);
        request.set_ct(ciphertext);

        CTReply reply;

        ClientContext context;

        Status status = stub_->SendCipherText(&context, request, &reply);

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

    if(readFile(p, "../../ParamP.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }
    if(readFile(g, "../../ParamG.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }

    a = NTL::RandomBnd(p);

    A = NTL::PowerMod(g, a, p);

    // 将NTL::ZZ转化为字符串发送
    std::string strA = zToString(A);
    std::string strB = sender.SendA(strA);

    // 将接收到的字符串转化为NTL::ZZ
    B = NTL::conv<NTL::ZZ>(strB.c_str());

    // 1、 计算B ^ a，k0
    NTL::ZZ B_a;
    B_a = NTL::PowerMod(B, a, p);
    std::string strB_a = zToString(B_a);
    std::string k0 = sha256(strB_a);

    // 2、计算(B / A) ^ a， k1
    NTL::ZZ A_inv, B_A;
    A_inv = NTL::InvMod(A, p);
    B_A = NTL::MulMod(B, A_inv, p);
    B_A = NTL::PowerMod(B_A, a, p);
    std::string strB_A = zToString(B_A);
    std::string k1 = sha256(strB_A);

    std::string M0 = "hello, i am M0 hd89sahf32yr89hfidsh8923hr";
    std::string M1 = "hello, i am M1 ch89f9hw892efhuidag7f3r9-f1241r";
    // 使用k0与k1对明文进行加密
    std::string ciphertext0 = encryptAES(M0, k0);
    std::cout << "ciphertext0: " << ciphertext0 << std::endl;
    std::string ciphertext1 = encryptAES(M1, k1);
    std::cout << "ciphertext1: " << ciphertext1 << std::endl;

    std::string ret0 = sender.SendCipherText(ciphertext0);
    std::cout << "received: " << ret0 << std::endl;

    std::string ret1 = sender.SendCipherText(ciphertext1);
    std::cout << "received: " << ret1 << std::endl;

    return 0;
}
