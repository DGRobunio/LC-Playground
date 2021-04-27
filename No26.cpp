//
// Created by zhang on 21/4/27.
//

#include "includes.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int result = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[result] != nums[i])
                nums[++result] = nums[i];
        }
        return ++result;
    }
};