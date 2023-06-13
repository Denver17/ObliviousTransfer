
#include <NTL/ZZ.h>
#include <fstream>
#include <sstream>
#include <openssl/sha.h>
#include <iomanip>
#include "../CryptoTools/StringCharArray.h"
#include "../CryptoTools/RWfile.h"
#include "../CryptoTools/ZZCal.h"
#include <random>
#include <vector>

#include <iostream>
#include <memory>
#include <string>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"

#include <grpcpp/grpcpp.h>

#include "NonInteractiveOT.grpc.pb.h"

ABSL_FLAG(std::string, target, "localhost:50051", "Server address");

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;
using grpc::Status;
using NonInteractiveOT::OT;
using NonInteractiveOT::Reply;
using NonInteractiveOT::Param;
using NonInteractiveOT::CipherText;

const long length = 2048;
NTL::ZZ p, g, C, beta0, beta1;
std::vector<unsigned int> seedValues0(length / 32), seedValues1(length / 32);   // 每个 unsigned int 占 32 比特

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
NTL::ZZ GenRandomZZ(const long &len, std::uniform_int_distribution<> &dis, std::mt19937 &gen) {
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

class OTSender {
public:
    OTSender(std::shared_ptr<Channel> channel)
        : stub_(OT::NewStub(channel)) {}

    std::string SendParams(const std::string &str0, const std::string &str1) {
        ClientContext context;
        Reply reply;
        std::unique_ptr<ClientWriter<Param> > writer(
        stub_->SendParams(&context, &reply));

        NTL::ZZ s0, s1;
        s0 = NTL::conv<NTL::ZZ>(str0.c_str());
        s1 = NTL::conv<NTL::ZZ>(str1.c_str());

        for (int i = 0; i < length; i++) {
            NTL::ZZ y0, y1, gamma0, gamma1, r0, r1, alpha0, alpha1, b0, b1;
            b0 = (s0 & 1);
            b1 = (s1 & 1);
            s0 = s0 >> 1;
            s1 = s1 >> 1;
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

            if (!writer->Write(param)) {
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

    std::string SendCipherText(const std::vector<std::string> &vec0, const std::vector<long> &len0, const std::vector<std::string> &vec1, const std::vector<long> &len1) {
        Reply reply;
        ClientContext context;
        std::unique_ptr<ClientWriter<CipherText> > writer(
        stub_->SendCipherText(&context, &reply));

        // 设置伪随机数生成器
        std::seed_seq seed0(seedValues0.begin(), seedValues0.end());
        std::mt19937 gen0(seed0);
        std::seed_seq seed1(seedValues1.begin(), seedValues1.end());
        std::mt19937 gen1(seed1);
        // 定义均匀分布
        std::uniform_int_distribution<> dis0(0, 1);
        std::uniform_int_distribution<> dis1(0, 1);

        for(int i = 0; i < vec0.size(); i++) {
            CipherText ct;

            NTL::ZZ r0, r1;
            r0 = NTL::conv<NTL::ZZ>(vec0[i].c_str());
            r1 = NTL::conv<NTL::ZZ>(vec1[i].c_str());
            
            NTL::ZZ Gs0, Gs1;
            Gs0 = GenRandomZZ(len0[i], dis0, gen0);
            Gs1 = GenRandomZZ(len1[i], dis1, gen1);

            std::cout << "r0 = " << r0 << std::endl;
            std::cout << "r1 = " << r1 << std::endl;

            r0 = (r0 ^ Gs0);
            r1 = (r1 ^ Gs1);

            std::string str0, str1;
            str0 = zToString(r0);
            str1 = zToString(r1);

            ct.set_ct0(str0);
            ct.set_ct1(str1);
            ct.set_len0(len0[i]);
            ct.set_len1(len1[i]);
            
            if (!writer->Write(ct)) {
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


void SendMessageByOTChannels(OTSender &sender, const NTL::ZZ &s0, const NTL::ZZ &s1) {
    // 将s0, s1作为随机数种子
    seedValues0 = ZZtoVector(s0);
    seedValues1 = ZZtoVector(s1);

    // 随机发送五组长度不一的数据
    int num = 5;
    std::vector<std::string> vec0(num), vec1(num);
    std::vector<long> len0(num), len1(num);
    for(int i = 0; i < num; i++) {
        NTL::ZZ r0, r1, l0, l1;
        long length0 = 0, length1 = 0;
        // 指定长度在1024比特以内
        NTL::RandomBits(l0, 10);
        NTL::RandomBits(l1, 10);
        conv(length0, l0);
        conv(length1, l1);
        NTL::RandomBits(r0, length0);
        NTL::RandomBits(r1, length1);
        
        std::string str0 = zToString(r0);
        std::string str1 = zToString(r1);
        vec0[i] = str0;
        vec1[i] = str1;
        len0[i] = length0;
        len1[i] = length1;
    }

    std::string ret = sender.SendCipherText(vec0, len0, vec1, len1);

    std::cout << "received: " << ret << std::endl;
    
    return ;
}

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

    NTL::ZZ s0, s1;
    NTL::RandomBits(s0, length);
    NTL::RandomBits(s1, length);

    std::cout << "s0 = " << s0 << std::endl;
    std::cout << "s1 = " << s1 << std::endl;

    std::string str0 = zToString(s0);
    std::string str1 = zToString(s1);

    std::string ret = sender.SendParams(str0, str1);
    std::cout << "received: " << ret << std::endl;

    SendMessageByOTChannels(sender, s0, s1);

    return 0;
}
