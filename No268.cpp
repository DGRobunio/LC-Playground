//
// Created by zhang on 21/5/14.
//

#include "includes.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {
//        int result = nums.size();
//        for (int i = 0; i < nums.size(); i++) {
//            result += i;
//            result -= nums[i];
//        }
//        return result;
        int result = 0;
        for (int i = 0; i < nums.size(); i++ ) {
            result ^= i;
            result ^= nums[i];
        }
        return result ^ nums.size();
    }
};
