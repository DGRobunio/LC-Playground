//
// Created by zhang on 21/4/25.
//
#include "includes.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int first, fp, bp;
        vector<vector<int>> result;
        for (first = 0; first < nums.size(); first++) {
            if (first > 0 && nums[first] == nums[first - 1])
                continue;
            int ans = 0;
            fp = first + 1;
            bp = nums.size() - 1;
            while (fp < bp) {
                if (fp > first+1 && nums[fp] == nums[fp-1]) {
                    fp++;
                    continue;
                }
                ans = nums[first] + nums[fp] + nums[bp];
                if (ans == 0) {
                    result.emplace_back(vector<int>{nums[first], nums[fp], nums[bp]});
                    fp++;
                } else if (ans > 0) {
                    bp--;
                } else {
                    fp++;
                }
            }
        }
        return result;
    }
};
