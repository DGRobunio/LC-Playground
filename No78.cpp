//
// Created by zhang on 21/4/29.
//

#include "includes.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
//        backtrack(result, nums, vector<int>{} ,0);
        result.emplace_back(vector<int>{});
        for (auto num: nums) {
            for (int i = result.size() - 1; i >= 0; i--) {
                auto temp = result[i];
                temp.emplace_back(num);
                result.emplace_back(temp);
            }
        }
        return result;
    }

private:
    void backtrack(vector<vector<int>>& result, vector<int>& nums, vector<int> temp, int pos) {
        result.emplace_back(temp);
        if (pos == nums.size()) return;
        for (int i = pos; i < nums.size(); i++) {
            temp.emplace_back(nums[i]);
            backtrack(result, nums, temp, i + 1);
            temp.pop_back();
        }
    }
};
