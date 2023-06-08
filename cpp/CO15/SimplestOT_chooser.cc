
#include <NTL/ZZ.h>
#include <sstream>
#include <fstream>
#include <string>
#include <openssl/sha.h>
// #include <openssl/aes.h>
// #include <openssl/rand.h>
#include "../CryptoTools/aes.h"

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

void stringToUnsignedCharArray(const std::string& str, unsigned char* array) {
    std::memcpy(array, str.data(), str.size());
}

std::string unsignedCharArrayToString(const unsigned char* array, size_t length) {
    return std::string(reinterpret_cast<const char*>(array), length);
}

// // PKCS7填充
// std::string pkcs7Padding(const std::string& data, size_t blocksize) {
//     size_t paddingLength = blocksize - (data.size() % blocksize);
//     std::string paddedData = data;
//     paddedData.append(paddingLength, static_cast<char>(paddingLength));
//     return paddedData;
// }

// // PKCS7去填充
// std::string pkcs7Unpadding(const std::string& data) {
//     unsigned char paddingLength = static_cast<unsigned char>(data[data.size() - 1]);
//     return data.substr(0, data.size() - paddingLength);
// }

// // 加密函数
// std::string encryptAES(const std::string& plaintext, const std::string& key) {
//     // 根据密钥设置AES加密上下文
//     AES_KEY aesKey;
//     AES_set_encrypt_key(reinterpret_cast<const unsigned char*>(key.c_str()), 128, &aesKey);

//     // 填充明文
//     std::string paddedPlaintext = pkcs7Padding(plaintext, AES_BLOCK_SIZE);

//     // 分配足够的内存来存储加密后的数据
//     std::string ciphertext;
//     ciphertext.resize(paddedPlaintext.size());

//     // 加密数据块
//     for (size_t i = 0; i < paddedPlaintext.size(); i += AES_BLOCK_SIZE) {
//         AES_encrypt(reinterpret_cast<const unsigned char*>(paddedPlaintext.c_str()) + i,
//                     reinterpret_cast<unsigned char*>(&ciphertext[i]), &aesKey);
//     }

//     return ciphertext;
// }

// // 解密函数
// std::string decryptAES(const std::string& ciphertext, const std::string& key) {
//     // 根据密钥设置AES解密上下文
//     AES_KEY aesKey;
//     AES_set_decrypt_key(reinterpret_cast<const unsigned char*>(key.c_str()), 128, &aesKey);

//     // 分配足够的内存来存储解密后的数据
//     std::string plaintext;
//     plaintext.resize(ciphertext.size());

//     // 解密数据块
//     for (size_t i = 0; i < ciphertext.size(); i += AES_BLOCK_SIZE) {
//         AES_decrypt(reinterpret_cast<const unsigned char*>(ciphertext.c_str()) + i,
//                     reinterpret_cast<unsigned char*>(&plaintext[i]), &aesKey);
//     }

//     // 去除填充
//     plaintext = pkcs7Unpadding(plaintext);

//     return plaintext;
// }


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
