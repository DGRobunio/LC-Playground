//
// Created by zhang on 21/4/27.
//


#include "includes.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0, right = size - 1;
        if (size == 0) return -1;
        if (size == 1) return nums[0]==target?0:-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid ;
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
