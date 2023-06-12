
#include <NTL/ZZ.h>
#include <fstream>
#include <sstream>
#include <openssl/sha.h>
#include <iomanip>
#include "../CryptoTools/aes.h"

#include <iostream>
#include <memory>
#include <string>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"

#include <grpcpp/grpcpp.h>

#ifdef BAZEL_BUILD
#include "examples/protos/NonInteractiveOT.grpc.pb.h"
#else
#include "NonInteractiveOT.grpc.pb.h"
#endif

ABSL_FLAG(std::string, target, "localhost:50051", "Server address");

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using NonInteractiveOT::OT;
using NonInteractiveOT::Reply;
using NonInteractiveOT::Param;

const long length = 2048;
NTL::ZZ p, g, C, beta0, beta1;

void stringToUnsignedCharArray(const std::string& str, unsigned char* array) {
    std::memcpy(array, str.data(), str.size());
}

std::string unsignedCharArrayToString(const unsigned char* array, size_t length) {
    return std::string(reinterpret_cast<const char*>(array), length);
}

std::string zToString(const NTL::ZZ &z) {
    std::stringstream buffer;
    buffer << z;
    return buffer.str();
}

std::string sha256(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.length());
    SHA256_Final(hash, &sha256);

    std::string ss = unsignedCharArrayToString(hash, SHA256_DIGEST_LENGTH);
    return ss;
}

int readFile(NTL::ZZ &value, std::string path) {
    // 从文本文件中读取 ZZ 变量
    std::ifstream inputFile(path);
    if (inputFile.is_open())
    {
        std::string line, res;
        while (std::getline(inputFile, line))
        {
            res += line;
        }
        // 将读取的字符串转换为 ZZ 类型
        value = NTL::conv<NTL::ZZ>(res.c_str());
        inputFile.close();
        return 1;
    }
    else
    {
        return -1;
    }
}

// 计算两数的内积
NTL::ZZ InnerProduct(NTL::ZZ v1, NTL::ZZ v2) {
    NTL::ZZ result;
    result = 0;
    while(v1 != 0 && v2 != 0) {
        result = (result ^ ((v1 & 1)  & (v2 & 1)));
        v1 >>= 1;
        v2 >>= 1;
    }
    return result;
}


class OTSender {
public:
    OTSender(std::shared_ptr<Channel> channel)
        : stub_(OT::NewStub(channel)) {}

    std::string SendParam(const std::string &strb0, const std::string &strb1) {
        NTL::ZZ y0, y1, gamma0, gamma1, r0, r1, alpha0, alpha1, b0, b1;
        b0 = NTL::conv<NTL::ZZ>(strb0.c_str());
        b1 = NTL::conv<NTL::ZZ>(strb1.c_str());
        y0 = NTL::RandomBnd(p - 1);
        y1 = NTL::RandomBnd(p - 1);
        gamma0 = NTL::PowerMod(beta0, y0, p);
        gamma1 = NTL::PowerMod(beta1, y1, p);
        NTL::RandomBits(r1, length);

        // 计算满足条件的随机数r0, r1
        do {
            NTL::RandomBits(r0, length);
        }
        while(InnerProduct(gamma0, r0) != b0);

        do {
            NTL::RandomBits(r1, length);
        }
        while(InnerProduct(gamma1, r1) != b1);

        // 计算α0, α1
        alpha0 = NTL::PowerMod(g, y0, p);
        alpha1 = NTL::PowerMod(g, y1, p);

        // 发送请求, 将ZZ转为字符串
        std::string stralpha0, stralpha1, strr0, strr1;
        stralpha0 = zToString(alpha0);
        stralpha1 = zToString(alpha1);
        strr0 = zToString(r0);
        strr1 = zToString(r1);
        Param param;
        param.set_alpha0(stralpha0);
        param.set_alpha1(stralpha1);
        param.set_r0(strr0);
        param.set_r1(strr1);


        Reply reply;

        ClientContext context;

        Status status = stub_->SendParam(&context, param, &reply);

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
    if(readFile(beta0, "../../ParamBeta0.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }
    if(readFile(beta1, "../../ParamBeta1.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }

    NTL::ZZ b0, b1;
    b0 = 0;
    b1 = 1;

    std::string str0 = zToString(b0);
    std::string str1 = zToString(b1);

    std::string ret = sender.SendParam(str0, str1);
    std::cout << "received: " << ret << std::endl;


    return 0;
}
