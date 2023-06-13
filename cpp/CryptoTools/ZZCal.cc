#include "ZZCal.h"

// 计算两数的内积
NTL::ZZ InnerProduct(NTL::ZZ v1, NTL::ZZ v2) {
    NTL::ZZ result;
    result = 0;
    while(v1 != 0 && v2 != 0) {
        result = (result ^ ((v1 & 1)  & (v2 & 1)));
        v1 >>= 1;
        v2 >>= 1;
    }
    return result;
}