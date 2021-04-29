//
// Created by zhang on 21/4/28.
//

#include "includes.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp;
        dp.resize(nums.size());
        int result = INT32_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                dp[i] = nums[i];
            } else {
                dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            }
            if (dp[i] > result) {
                result = dp[i];
            }
        }
        return result;
    }
};
