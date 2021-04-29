//
// Created by zhang on 21/4/28.
//

#include "includes.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() < 2)
            return vector<vector<int>> {nums};
        vector<vector<int>> result;
        backTrack(result, nums, 0, nums.size());
        return result;
    }

private:
    void backTrack(vector<vector<int>>& result, vector<int>nums, int pos, int length) {
        if (pos == length) {
            result.emplace_back(nums);
            return;
        }
        for (int i = pos; i < length; i++) {
            swap(nums[pos], nums[i]);
            backTrack(result, nums, pos + 1, length);
            swap(nums[pos], nums[i]);
        }
    }
};
