//
// Created by zhang on 21/4/29.
//

#include "includes.h"


class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) return n;
        vector<int> dp(n + 1,1);
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-2] + dp[i-1];
        }
        return dp[n];
    }
};
