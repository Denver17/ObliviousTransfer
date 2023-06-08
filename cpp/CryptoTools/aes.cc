#include "aes.h"
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