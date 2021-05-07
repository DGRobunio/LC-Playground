//
// Created by zhang on 21/5/7.
//

#include "includes.h"

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        int left = 1, right = 1;
        vector<int> result(size, 1);
        for (int i = 0; i < size; i++) {
            result[i] *= left;
            left *= nums[i];

            result[size - 1 - i] *= right;
            right *= nums[size - 1 - i];
        }
        return result;
    }
};