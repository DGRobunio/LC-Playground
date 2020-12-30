//
// Created by zhang on 20/12/29.
//

#include "includes.h"
class Solution {
public:
    int mySqrt(int x) {
        double result = 1.0;
        double check = 0.0;

        do {
            result = (x / result + result) / 2.0;
            check = result * result - x;
        } while((check >= 0 ? check : (-1) * check) > 0.1);
        return result;
    }
};