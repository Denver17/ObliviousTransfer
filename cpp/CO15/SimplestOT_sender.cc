
#include <NTL/ZZ.h>
#include <fstream>
#include <sstream>
#include <openssl/sha.h>
#include <iomanip>
#include <openssl/aes.h>
#include <openssl/rand.h>

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

void stringToUnsignedCharArray(const std::string& str, unsigned char* array) {
    std::memcpy(array, str.data(), str.size());
}

std::string unsignedCharArrayToString(const unsigned char* array, size_t length) {
    return std::string(reinterpret_cast<const char*>(array), length);
}

// PKCS7填充
std::string pkcs7Padding(const std::string& data, size_t blocksize) {
    size_t paddingLength = blocksize - (data.size() % blocksize);
    std::string paddedData = data;
    paddedData.append(paddingLength, static_cast<char>(paddingLength));
    return paddedData;
}

// PKCS7去填充
std::string pkcs7Unpadding(const std::string& data) {
    unsigned char paddingLength = static_cast<unsigned char>(data[data.size() - 1]);
    return data.substr(0, data.size() - paddingLength);
}

// 加密函数
std::string encryptAES(const std::string& plaintext, const std::string& key) {
    // 根据密钥设置AES加密上下文
    AES_KEY aesKey;
    AES_set_encrypt_key(reinterpret_cast<const unsigned char*>(key.c_str()), 128, &aesKey);

    // 填充明文
    std::string paddedPlaintext = pkcs7Padding(plaintext, AES_BLOCK_SIZE);

    // 分配足够的内存来存储加密后的数据
    std::string ciphertext;
    ciphertext.resize(paddedPlaintext.size());

    // 加密数据块
    for (size_t i = 0; i < paddedPlaintext.size(); i += AES_BLOCK_SIZE) {
        AES_encrypt(reinterpret_cast<const unsigned char*>(paddedPlaintext.c_str()) + i,
                    reinterpret_cast<unsigned char*>(&ciphertext[i]), &aesKey);
    }

    return ciphertext;
}

// 解密函数
std::string decryptAES(const std::string& ciphertext, const std::string& key) {
    // 根据密钥设置AES解密上下文
    AES_KEY aesKey;
    AES_set_decrypt_key(reinterpret_cast<const unsigned char*>(key.c_str()), 128, &aesKey);

    // 分配足够的内存来存储解密后的数据
    std::string plaintext;
    plaintext.resize(ciphertext.size());

    // 解密数据块
    for (size_t i = 0; i < ciphertext.size(); i += AES_BLOCK_SIZE) {
        AES_decrypt(reinterpret_cast<const unsigned char*>(ciphertext.c_str()) + i,
                    reinterpret_cast<unsigned char*>(&plaintext[i]), &aesKey);
    }

    // 去除填充
    plaintext = pkcs7Unpadding(plaintext);

    return plaintext;
}

// // AES-256 ECB encryption
// void aes_encrypt(const unsigned char* key, const unsigned char* plaintext, unsigned char* ciphertext) {
//     AES_KEY aesKey;
//     AES_set_encrypt_key(key, 256, &aesKey);
//     AES_encrypt(plaintext, ciphertext, &aesKey);
// }

// // AES-256 ECB decryption
// void aes_decrypt(const unsigned char* key, const unsigned char* ciphertext, unsigned char* plaintext) {
//     AES_KEY aesKey;
//     AES_set_decrypt_key(key, 256, &aesKey);
//     AES_decrypt(ciphertext, plaintext, &aesKey);
// }

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

private:
    std::unique_ptr<OT::Stub> stub_;
};

int main(int argc, char** argv) {
    absl::ParseCommandLine(argc, argv);
    std::string target_str = absl::GetFlag(FLAGS_target);
    OTSender sender(
        grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));

    if(sender.readFile(p, "../../ParamP.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }
    if(sender.readFile(g, "../../ParamG.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }

    a = NTL::RandomBnd(p);

    A = NTL::PowerMod(g, a, p);

    // 将NTL::ZZ转化为字符串发送
    std::stringstream strA;
    strA << A;
    std::string user = strA.str();
    std::string strB = sender.SendA(user);

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
