//
// Created by zhang on 21/5/6.
//

#include "includes.h"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> numMap;
        for (auto num: nums) {
            if (numMap.find(num) != numMap.end()) {
                return true;
            } else {
                numMap[num] = 1;
            }
        }
        return false;
    }
};
