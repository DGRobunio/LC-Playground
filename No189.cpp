//
// Created by zhang on 21/1/8.
//

#include "includes.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        while (k--) {
            nums.insert(nums.begin(),nums.back());
            nums.pop_back();
        }
    }
};