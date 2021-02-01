//
// Created by zhang on 21/2/1.
//
#include "includes.h"

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        int delta = (sumA - sumB) / 2;
        unordered_set<int> rec(A.begin(), A.end());
        vector<int> result;
        for (const auto& by: B) {
            int ax = by + delta;
            if (rec.count(ax)) {
                result = vector<int> {ax, by};
            }
        }
        return result;
    }
};
