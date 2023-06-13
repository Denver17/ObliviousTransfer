
#include <NTL/ZZ.h>
#include <sstream>
#include <fstream>
#include <openssl/sha.h>
#include "../CryptoTools/StringCharArray.h"
#include "../CryptoTools/RWfile.h"
#include "../CryptoTools/ZZCal.h"
#include <vector>
#include <random>

#include <iostream>
#include <memory>
#include <string>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/strings/str_format.h"

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include "NonInteractiveOT.grpc.pb.h"


using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;
using NonInteractiveOT::OT;
using NonInteractiveOT::Reply;
using NonInteractiveOT::Param;
using NonInteractiveOT::CipherText;

ABSL_FLAG(uint16_t, port, 50051, "Server port for the service");

const int length = 2048;
int i;
NTL::ZZ p, g, C, x, beta0, beta1;
std::string kR;
std::vector<unsigned int> seedValues0(length / 32), seedValues1(length / 32);

// 将ZZ变量转化为vecor<unsigned int>
std::vector<unsigned int> ZZtoVector(const NTL::ZZ &s) {
    std::vector<unsigned int> seedValues(length / 32);
    NTL::ZZ t = s;
    // 将s作为随机数种子
    for(int i = 0; i < seedValues.size(); i++) {
        unsigned int tmp = 1, val = 0;
        for(int j = 0; j < 32; j++) {
            if((t & 1) == 1) {
                val = val + tmp;
            }
            // 避免溢出
            if(j != 31) {
                tmp = tmp << 1;
            }
            t = t >> 1;
        }
        seedValues[i] = val;
    }
    return seedValues;
}

// 由指定的伪随机数生成器生成给定比特长度的ZZ变量
NTL::ZZ GenRandomZZ(const int &len, std::uniform_int_distribution<> &dis, std::mt19937 &gen) {
    NTL::ZZ res, val;
    res = 0;
    val = 1;
    for(int j = 0; j < len; j++) {
        int b = dis(gen);
        if(b == 1) {
            res = res + val;
        }
        val = val << 1;
    }
    return res;
}


class OTServiceImpl final : public OT::Service {
    Status SendParams(ServerContext* context, ServerReader<Param>* reader,
                    Reply* reply) override {
        Param param;
        NTL::ZZ s0, s1, val;
        s0 = 0;
        s1 = 0;
        val = 1;
        while (reader->Read(&param)) {
            NTL::ZZ alpha0, alpha1, r0, r1;
            std::string stralpha0, stralpha1, strr0, strr1;
            stralpha0 = param.alpha0();
            stralpha1 = param.alpha1();
            strr0 = param.r0();
            strr1 = param.r1();

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

            if(b0 == 1) {
                s0 = s0 + val;
            }
            if(b1 == 1) {
                s1 = s1 + val;
            }
            val = val << 1;
        }
        std::cout << "s0 = " << s0 << std::endl;
        std::cout << "s1 = " << s1 << std::endl;

        // 接收到s0, s1之后，设置随机数种子
        seedValues0 = ZZtoVector(s0);
        seedValues1 = ZZtoVector(s1);

        std::string res = "i have received params";
        reply->set_message(res);
        return Status::OK;
    }

    Status SendCipherText(ServerContext* context, ServerReader<CipherText>* reader,
                    Reply* reply) override {
        CipherText ct;
        // 设置伪随机数生成器
        std::seed_seq seed0(seedValues0.begin(), seedValues0.end());
        std::mt19937 gen0(seed0);
        std::seed_seq seed1(seedValues1.begin(), seedValues1.end());
        std::mt19937 gen1(seed1);
        // 定义均匀分布
        std::uniform_int_distribution<> dis0(0, 1);
        std::uniform_int_distribution<> dis1(0, 1);

        while (reader->Read(&ct)) {
            int len0, len1;
            len0 = ct.len0();
            len1 = ct.len1();
            
            NTL::ZZ r0, r1;
            r0 = NTL::conv<NTL::ZZ>(ct.ct0().c_str());
            r1 = NTL::conv<NTL::ZZ>(ct.ct1().c_str());

            // 使用伪随机数生成器生成指定长度的数
            NTL::ZZ Gs0, Gs1;
            Gs0 = GenRandomZZ(ct.len0(), dis0, gen0);
            Gs1 = GenRandomZZ(ct.len1(), dis1, gen1);

            r0 = (r0 ^ Gs0);
            r1 = (r1 ^ Gs1);

            std::cout << "r0 = " << r0 << std::endl;
            std::cout << "r1 = " << r1 << std::endl;
        }

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
