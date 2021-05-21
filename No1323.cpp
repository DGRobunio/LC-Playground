//
// Created by zhang on 21/5/20.
//

#include "includes.h"

class Solution {
public:
    int maximum69Number (int num) {
        int mod = 10000;
        while (mod) {
            if ((num / mod) % 10 == 6) {
                num += 3 * mod;
                break;
            }
            mod /= 10;
        }
        return num;
    }
};
