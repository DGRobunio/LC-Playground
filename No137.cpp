//
// Created by zhang on 21/1/5.
//

#include "includes.h"

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;

        for (auto& num: nums) {
            a = (a ^ num) & ~b; //低位
            b = (b ^ num) & ~a; //高位
        }

        return a;
    }
};