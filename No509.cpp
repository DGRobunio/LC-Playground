//
// Created by zhang on 21/1/4.
//
#include "includes.h"

class Solution {
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        } else {
            return fib(n-1) + fib(n-2);
        }
    }
};