//
// Created by zhang on 21/5/6.
//

#include "includes.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Boyer-Moore 投票算法
        int candidate = -1;
        int count = 0;
        for (auto num: nums) {
            if (num == candidate) {
                count++;
            } else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};
