//
// Created by zhang on 21/1/14.
//
#include "includes.h"

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> result;
        for (int i = 0; i < A.size(); i++) {
            if (i == 0) {
                if (A[i] == 0) {
                    result.emplace_back(true);
                } else {
                    result.emplace_back(false);
                }

            } else {
                A[i] += A[i-1] * 2;
                A[i] = A[i] % 5;
                if (A[i] % 5 == 0) {
                    result.emplace_back(true);
                } else {
                    result.emplace_back(false);
                }
            }
        }
        return result;
    }
};
