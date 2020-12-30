//
// Created by zhang on 20/12/30.
//

#include "includes.h"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n) {
            result += n % 2;
            n >>= 1;
        }
        return result;

        // 使用bitset存储二进制数位
//        return bitset<32>(n).count();
    }
};