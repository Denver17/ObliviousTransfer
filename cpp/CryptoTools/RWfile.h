#ifndef _RWFILE_H_
#define _RWFILE_H_

#include "StringCharArray.h"
#include <fstream>

int readFile(NTL::ZZ &value, std::string path);

int writeFile(const NTL::ZZ &value, std::string path);

#endif