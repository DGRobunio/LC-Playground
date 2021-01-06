//
// Created by zhang on 21/1/6.
//
#include "includes.h"

class Solution {
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        } else {
            int sum = 0, a = 0, b = 1;
            while (n--) {
                sum = a + b;
                a = b % 1000000007;
                b = sum % 1000000007;
            }

            return a ;
        }
    }
};
