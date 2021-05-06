//
// Created by zhang on 21/5/6.
//

#include "includes.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        if (prices.size() > 1) {
            for (int i = 1; i < prices.size(); i++) {
                int delta = prices[i] - prices[i - 1];
                if (delta > 0) {
                    result += delta;
                }
            }
        }
        return result;
    }
};
