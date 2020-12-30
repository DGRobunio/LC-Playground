//
// Created by zhang on 20/12/30.
//

#include "includes.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }

    int binarySearch(vector<int>& nums, int left, int right, int target) {
        int tempPos = (left + right) / 2;

        if (nums[tempPos] == target) {
            return tempPos;
        }

        if (left == right) {
            return -1;
        }

        if (nums[tempPos] > target) {
            return binarySearch(nums, left, tempPos, target);
        }else {
            return binarySearch(nums, tempPos + 1, right, target);
        }
    }

};