//
// Created by zhang on 21/4/26.
//
#include "includes.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int first, frontPointer, backPointer, result = INT_MAX;
        for (first = 0; first < nums.size(); first++) {
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            frontPointer = first + 1;
            backPointer = nums.size() - 1;
            int delta;
            while (frontPointer < backPointer) {
                if (frontPointer > first + 1 && nums[frontPointer] == nums[frontPointer - 1]) {
                    frontPointer++;
                    continue;
                }
                delta = nums[first] + nums[frontPointer] + nums[backPointer];

                if (delta - target == 0) {
                    return target;
                } else if (delta - target > 0) {
                    backPointer--;
                } else {
                    frontPointer++;
                }
                if (abs((long long)delta - target) < abs((long long)result - target)) {
                    result = delta;
                }
            }
        }
        return result;
    }
};
