//
// Created by zhang on 21/5/7.
//

#include "includes.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        auto it = nums.end();
        it -= k;
        return *it;
    }
};
