
#include <NTL/ZZ.h>
#include <sstream>
#include <fstream>
#include <openssl/sha.h>
#include "../CryptoTools/aes.h"
#include "../CryptoTools/sha256.h"
#include "../CryptoTools/StringCharArray.h"
#include "../CryptoTools/RWfile.h"

#include <iostream>
#include <memory>
#include <string>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/strings/str_format.h"

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#ifdef BAZEL_BUILD
#include "examples/protos/SimplestOT.grpc.pb.h"
#else
#include "SimplestOT.grpc.pb.h"
#endif

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using SimplestOT::OT;
using SimplestOT::BReply;
using SimplestOT::ARequest;
using SimplestOT::CTRequest;
using SimplestOT::CTReply;

ABSL_FLAG(uint16_t, port, 50051, "Server port for the service");

int c;
NTL::ZZ p, g, b, A, B, A_b;
std::string kR;


class OTServiceImpl final : public OT::Service {
    Status SendA(ServerContext* context, const ARequest* request,
                    BReply* reply) override {
    NTL::ZZ g_b = NTL::PowerMod(g, b, p);
    std::string strA = request->a();
    A = NTL::conv<NTL::ZZ>(strA.c_str());
    A_b = NTL::PowerMod(A, b, p);
    std::string strA_b = zToString(A_b);
    kR = sha256(strA_b);
    unsigned char keyR[(int)kR.size()];
    stringToUnsignedCharArray(kR, keyR);

    if(c == 0) {
        B = g_b;
    }
    else {
        B = NTL::MulMod(A, g_b, p);
    }

    std::stringstream strB;
    strB << B;
    std::string res = strB.str();
    reply->set_b(res);
    return Status::OK;
    }

    Status SendCipherText(ServerContext* context, const CTRequest* request,
                    CTReply* reply) {
    std::string decryptedText = decryptAES(request->ct(), kR);
    std::cout << "Decrypted text: " << decryptedText << std::endl;
    std::cout << "pt = " << decryptedText << std::endl;

    std::string res = "i have received ciphertext";
    reply->set_message(res);
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
    std::cin >> c;

    if(readFile(p, "../../ParamP.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }
    if(readFile(g, "../../ParamG.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }

    b = NTL::RandomBnd(p);

    absl::ParseCommandLine(argc, argv);
    RunServer(absl::GetFlag(FLAGS_port));
    return 0;
}
