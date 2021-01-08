//
// Created by zhang on 21/1/8.
//
#include "includes.h"

class Solution {
public:

    vector<int> triboVector;

    int tribonacci(int n) {
        tribonacciStack(n);
        return triboVector[n];
    }

    void tribonacciStack(int n) {
        triboVector.emplace_back(0);
        triboVector.emplace_back(1);
        triboVector.emplace_back(1);
        for (int i = 3; i <= n; i++) {
            triboVector.emplace_back(triboVector[i-1] + triboVector[i-2] + triboVector[i-3]);
        }
    }
};
