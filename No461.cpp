//
// Created by zhang on 21/5/27.
//

#include "includes.h"

class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        while (x != 0 || y != 0) {
            int bitX = x % 2, bitY = y % 2;
            if (bitX ^ bitY) {
                result++;
            }
            x >>= 1;
            y >>= 1;
        }
        return result;
    }
};
