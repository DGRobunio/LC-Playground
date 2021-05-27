//
// Created by zhang on 21/5/25.
//

#include "includes.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        int maxRight = 0;
        for (int i = 0; i < n; i++) {
            if (i <= maxRight) {
                maxRight = max(i + nums[i], maxRight);
                if (maxRight >= n - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};
