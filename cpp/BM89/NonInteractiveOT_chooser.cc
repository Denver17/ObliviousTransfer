
#include <NTL/ZZ.h>
#include <sstream>
#include <fstream>
#include <openssl/sha.h>
#include "../CryptoTools/StringCharArray.h"
#include "../CryptoTools/RWfile.h"
#include "../CryptoTools/ZZCal.h"

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
#include "examples/protos/NonInteractiveOT.grpc.pb.h"
#else
#include "NonInteractiveOT.grpc.pb.h"
#endif

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using NonInteractiveOT::OT;
using NonInteractiveOT::Reply;
using NonInteractiveOT::Param;

ABSL_FLAG(uint16_t, port, 50051, "Server port for the service");

int i;
NTL::ZZ p, g, C, x, beta0, beta1;
std::string kR;


class OTServiceImpl final : public OT::Service {
    Status SendParam(ServerContext* context, const Param* param,
                    Reply* reply) override {
        NTL::ZZ alpha0, alpha1, r0, r1;
        std::string stralpha0, stralpha1, strr0, strr1;
        stralpha0 = param->alpha0();
        stralpha1 = param->alpha1();
        strr0 = param->r0();
        strr1 = param->r1();

        // 将字符串转为ZZ类型
        alpha0 = NTL::conv<NTL::ZZ>(stralpha0.c_str());
        alpha1 = NTL::conv<NTL::ZZ>(stralpha1.c_str());
        r0 = NTL::conv<NTL::ZZ>(strr0.c_str());
        r1 = NTL::conv<NTL::ZZ>(strr1.c_str());

        NTL::ZZ gamma0, gamma1, b0, b1;
        gamma0 = NTL::PowerMod(alpha0, x, p);
        gamma1 = NTL::PowerMod(alpha1, x, p);
        b0 = InnerProduct(gamma0, r0);
        b1 = InnerProduct(gamma1, r1);

        std::cout << "b0 = " << b0 << std::endl;
        std::cout << "b1 = " << b1 << std::endl;

        std::string res = "i have received params";
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
    std::cin >> i;

    if(readFile(p, "../../ParamP.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }
    if(readFile(g, "../../ParamG.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }
    if(readFile(C, "../../ParamC.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }

    x = NTL::RandomBnd(p - 1);

    if(i == 0) {
        beta0 = NTL::PowerMod(g, x, p);
        beta1 = NTL::InvMod(beta0, p);
        beta1 = NTL::MulMod(beta1, C, p);
    }
    else {
        beta1 = NTL::PowerMod(g, x, p);
        beta0 = NTL::InvMod(beta1, p);
        beta0 = NTL::MulMod(beta0, C, p);
    }

    if(writeFile(beta0, "../../ParamBeta0.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }
    if(writeFile(beta1, "../../ParamBeta1.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }

    absl::ParseCommandLine(argc, argv);
    RunServer(absl::GetFlag(FLAGS_port));
    return 0;
}
