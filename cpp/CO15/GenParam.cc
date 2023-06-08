#include <NTL/ZZ.h>
#include <NTL/tools.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

std::string zToString(const NTL::ZZ &z) {
    std::stringstream buffer;
    buffer << z;
    return buffer.str();
}

int writeFile(const NTL::ZZ &value, std::string path) {
    // 将 ZZ 变量写入到文本文件中
    std::ofstream file(path);
    if (file.is_open())
    {
        // 将 ZZ 变量转换为字符串并写入文件
        file << zToString(value) << std::endl;
        file.close();
        std::cout << "Variable written to file." << std::endl;
        return 1;
    }
    else
    {
        return -1;
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

int main()
{
    // 设置随机数种子
    // NTL::SetSeed(NTL::to_ZZ(time(NULL)));

    // 生成一个大素数 p
    NTL::ZZ p;
    NTL::GenPrime(p, 2048);

    // 选择一个随机整数 g 作为生成元，范围在 [2, p-1] 之间
    NTL::ZZ g;
    NTL::RandomBnd(g, p);

    if(g < 2)   return 0;

    std::cout << "p = " << p << std::endl;
    std::cout << "g = " << g << std::endl;

    if(writeFile(p, "ParamP.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }

    NTL::ZZ p_;
    if(readFile(p_, "ParamP.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }

    if(p_ != p) {
        std::cerr << "the two numbers are not equal." << std::endl;
    }

    if(writeFile(g, "ParamG.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }

    NTL::ZZ g_;
    if(readFile(g_, "ParamG.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }

    if(g_ != g) {
        std::cerr << "the two numbers are not equal." << std::endl;
    }
    
    return 0;
}
