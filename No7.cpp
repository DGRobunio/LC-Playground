//
// Created by zhang on 20/12/29.
//
#include "includes.h"

class Solution {
public:
    int reverse(int x) {
        return reverseOne(x, 0);
    }

    int reverseOne(long originNum, long resultNum) {
        if (originNum == 0) {
            if(resultNum < -2147483648 || resultNum > 2147483647) {
                return 0;
            } else {
                return (int)resultNum;
            }
        }
        return reverseOne(originNum/10, resultNum*10 + originNum%10);
    }
};
