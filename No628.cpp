//
// Created by zhang on 21/1/20.
//
#include "includes.h"

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int x, int y)->auto {return x < y;});
        int n = nums.size();
        return max(nums[0] * nums[1] * nums[n-1],
                   nums[n-3] * nums[n-2] * nums[n-1]);
    }
};
