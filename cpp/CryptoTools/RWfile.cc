#include "RWfile.h"

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