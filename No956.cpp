//
// Created by zhang on 20/12/29.
//
#include "includes.h"

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int rodsNum = rods.size();
        // accumulate 累加函数 <numberic>
        int lengthSum = accumulate(rods.begin(), rods.end(), 0);
        vector<int> dp(lengthSum+1, 0);
        // dp 中 key 为两边钢筋高度差； value 为 两边钢筋的总高度
        for (int i = 0; i < rodsNum; i++) {
            auto dpTemp = dp;
            for (int j = 0; j <= lengthSum; j++) {
                // 总长度至少要等于高度差
                if (dp[j] < j) continue;
                //当添加到长边时
                int deltaLength = j + rods[i];
                dpTemp[deltaLength] = max(dpTemp[deltaLength], dp[j] + rods[i]);
                //当添加到短边时
                deltaLength = abs(j - rods[i]);
                dpTemp[deltaLength] = max(dpTemp[deltaLength], dp[j] + rods[i]);
            }
            swap(dp, dpTemp);
        }
        return dp[0]/2;
    }
};