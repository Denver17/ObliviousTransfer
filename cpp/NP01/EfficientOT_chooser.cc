
#include <NTL/ZZ.h>
#include <sstream>
#include <fstream>
#include <openssl/sha.h>
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
#include "absl/strings/str_format.h"

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include "EfficientOT.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;
using EfficientOT::OT;
using EfficientOT::Reply;
using EfficientOT::Param;
using EfficientOT::Request;
using EfficientOT::CipherText;

ABSL_FLAG(uint16_t, port, 50051, "Server port for the service");

int sigma;
const int N = 5;
NTL::ZZ p, g, g_r, k, R, PK0, PKsigma, PKsigma_r;
std::vector<NTL::ZZ> C(N), CT(N);

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


class OTServiceImpl final : public OT::Service {
    Status RequestParam(ServerContext* context, const Request* request,
                    Param* param) override {
        // 接收参数R
        std::string strR = request->r();
        R = NTL::conv<NTL::ZZ>(strR.c_str());
        // 发送PK0
        std::string strPK0 = zToString(PK0);
        param->set_pk0(strPK0);
        return Status::OK;
    }

    Status SendCipherText(ServerContext* context, ServerReader<CipherText>* reader,
                    Reply* reply) override {
        CipherText ciphertext;

        int idx = 0;
        while (reader->Read(&ciphertext) && idx < N) {
            CT[idx] = NTL::conv<NTL::ZZ>(ciphertext.ct().c_str());
            idx++;
        }

        // 计算明文
        std::string strR = zToString(R);
        std::string str = zToString(PKsigma_r) + strR + std::to_string(sigma);
        std::string res = sha256(str);
        // NTL::ZZ h = NTL::conv<NTL::ZZ>(res.c_str());
        NTL::ZZ h = stringToZZ(res);
        NTL::ZZ Msigma = h ^ CT[sigma];

        std::cout<< Msigma << std::endl;

        std::string ret = "i have received ciphertext";
        reply->set_message(ret);
        return Status::OK;
    }

};

void RunServer(uint16_t port) {
    std::string server_address = absl::StrFormat("0.0.0.0:%d", port);
    OTServiceImpl service;

    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    ServerBuilder builder;

    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;

    server->Wait();
}

int main(int argc, char** argv) {
    // 选定需要的明文编号
    std::cin >> sigma;

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
    if(readFile(g_r, "../../param/ParamG_R.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }
    
    // 开始OT
    NTL::RandomBnd(k, p);
    PKsigma = NTL::PowerMod(g, k, p);
    if(sigma != 0) {
        NTL::ZZ val = NTL::InvMod(PKsigma, p);
        PK0 = NTL::MulMod(C[sigma], val, p);
    }
    else {
        PK0 = NTL::PowerMod(g, k, p);
    }

    // 计算PKsigma ^ r, 即(g ^ r) ^ k
    PKsigma_r = NTL::PowerMod(g_r, k, p);

    absl::ParseCommandLine(argc, argv);
    RunServer(absl::GetFlag(FLAGS_port));
    return 0;
}
