#include <NTL/ZZ.h>
#include <NTL/tools.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

const int N = 5;

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

    // 生成一个大素数 p
    NTL::ZZ p;
    NTL::GenPrime(p, 2048);

    // 选择一个随机整数 g 作为生成元，范围在 [2, p-2] 之间
    NTL::ZZ g;
    NTL::RandomBnd(g, p - 1);
    if(g < 2)   return 0;

    // 选择参数C
    std::vector<NTL::ZZ> vec(N);
    for(int i = 1; i < N; i++) {
        NTL::RandomBnd(vec[i], p);
        if(vec[i] < 2)      return 0;
    }

    // 选择参数g ^ r
    NTL::ZZ r, g_r;
    NTL::RandomBnd(r, p);
    g_r = NTL::PowerMod(g, r, p);

    if(writeFile(p, "./param/ParamP.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }

    if(writeFile(g, "./param/ParamG.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }


    std::string basePath;
    basePath = "./param/Param";
    for(int i = 1; i < N; i++) {
        std::string path = basePath + "C" + std::to_string(i) + ".txt";
        if(writeFile(vec[i], path) < 0) {
            std::cerr << "Unable to open file." << std::endl;
            return 0;
        }
    }

    if(writeFile(r, "./param/ParamR.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }

    if(writeFile(g_r, "./param/ParamG_R.txt") < 0) {
        std::cerr << "Unable to open file." << std::endl;
        return 0;
    }

    
    return 0;
}

