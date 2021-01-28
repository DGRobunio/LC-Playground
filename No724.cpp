//
// Created by zhang on 21/1/28.
//
#include "includes.h"

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int result = -1;
        if (nums.empty()) {
            return result;
        }
        if (nums.size() == 1) {
            return 0;
        }
        if (nums.size() == 2) {
            return result;
        }
        int leftSum = 0, rightSum = 0;
        for (const auto& num :nums) {
            rightSum += num;
        }

        for (int i = 0; i < nums.size(); i++) {
            rightSum -= nums[i];
            if (i > 0) {
                leftSum += nums[i-1];
            }
            if (leftSum == rightSum) {
                result = i;
                break;
            }
        }
        return result;
    }
};