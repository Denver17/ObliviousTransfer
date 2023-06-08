#ifndef _AES_H_
#define _AES_H_

#include <openssl/aes.h>
#include <openssl/rand.h>
#include <string>

// PKCS7填充
std::string pkcs7Padding(const std::string& data, size_t blocksize);

// PKCS7去填充
std::string pkcs7Unpadding(const std::string& data);

// 加密函数
std::string encryptAES(const std::string& plaintext, const std::string& key);

// 解密函数
std::string decryptAES(const std::string& ciphertext, const std::string& key);

#endif