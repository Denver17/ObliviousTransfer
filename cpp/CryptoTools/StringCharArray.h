#ifndef _STRINGCHARARRAY_H_
#define _STRINGCHARARRAY_H_

#include <string>
#include <cstring>
#include <sstream>
#include <NTL/ZZ.h>

void stringToUnsignedCharArray(const std::string& str, unsigned char* array);

std::string unsignedCharArrayToString(const unsigned char* array, size_t length);

std::string zToString(const NTL::ZZ &z);

#endif