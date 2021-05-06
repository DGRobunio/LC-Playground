//
// Created by zhang on 21/4/30.
//

#include "includes.h"

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.emplace_back(0);
        if (n != 0) {
            int head = 1;
            for (int i = 0; i < n; i++) {
                for (int j = result.size() - 1; j >= 0; j--) {
                    result.emplace_back(head + result[j]);
                }
                head <<= 1;
            }
        }
        return result;
    }
};
