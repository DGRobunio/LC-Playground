//
// Created by zhang on 21/5/25.
//

#include "includes.h"

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int iMax = values[0] + 0;
        int result = INT_MIN;
        for (int i = 1; i < values.size(); i++) {
            result = max(result, iMax + values[i] - i);
            iMax = max(iMax, i + values[i]);
        }
        return result;
    }
};
