#ifndef _SHA256_H_
#define _SHA256_H_

#include <openssl/sha.h>
#include <string>
#include "StringCharArray.h"

std::string sha256(const std::string& input);

#endif