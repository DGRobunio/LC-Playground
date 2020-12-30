//
// Created by zhang on 20/12/30.
//

#include "includes.h"

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0)
            return false;
        if(bitset<32>(n).count() == 1) {
            return true;
        } else {
            return false;
        }
    }
};