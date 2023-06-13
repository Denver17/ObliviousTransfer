#include "StringCharArray.h"

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