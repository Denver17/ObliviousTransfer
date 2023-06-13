#include "sha256.h"

std::string sha256(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.length());
    SHA256_Final(hash, &sha256);

    std::string ss = unsignedCharArrayToString(hash, SHA256_DIGEST_LENGTH);
    return ss;
}