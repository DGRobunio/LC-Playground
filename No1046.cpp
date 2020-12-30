//
// Created by zhang on 20/12/30.
//

#include "includes.h"

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1) {
            return stones[0];
        }

        if (stones.size() == 2) {
            return abs(stones[0] - stones[1]);
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; int j < stones.size() - i - 1; j++) {
                if (stones[j] > stones[j+1]) {
                    auto temp = stones[j];
                    stones[j] = stones[j+1];
                    stones[j+1] = temp;
                }
            }
        }

        stones[stones.size()-2] = abs(stones[stones.size()-2] - stones[stones.size()-1]);
        stones.pop_back();
        return lastStoneWeight(stones);
    }
};
