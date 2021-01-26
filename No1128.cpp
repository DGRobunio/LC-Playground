//
// Created by zhang on 21/1/26.
//
#include "includes.h"

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int result = 0;
        if ( dominoes.empty()) {
            return result;
        }
        int counter[100] = {0};
        for (auto& domino: dominoes) {
            if (domino[0] > domino[1]) {
                swap(domino[0], domino[1]);
            }
            result += counter[domino[0] * 10 + domino[1]]++;
        }
        return result;
    }
};
