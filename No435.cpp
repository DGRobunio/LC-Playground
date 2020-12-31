//
// Created by zhang on 20/12/31.
//

#include "includes.h"

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int result = 0;
        if (!intervals.empty()) {
            sort(intervals.begin(),intervals.end(), compare);
            int endPoint = intervals[0][1];
            for (int i = 1; i < intervals.size(); i++) {
                if (endPoint > intervals[i][0]) {
                    result++;
                    endPoint = min(endPoint, intervals[i][1]);
                } else {
                    endPoint = intervals[i][1];
                }
            }

        }
        return result;
    }

    static bool compare(const vector<int> &lhs, const vector<int> &rhs) {
        return lhs[0] < rhs[0];
    }
};