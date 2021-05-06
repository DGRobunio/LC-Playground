//
// Created by zhang on 21/4/29.
//

#include "includes.h"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        int firstPoint = m - 1, secondPoint = n - 1;
        int pos = m + n - 1;
        while (firstPoint >= 0 || secondPoint >= 0) {
            if (firstPoint == -1) {
                nums1[pos--] = nums2[secondPoint--];
            } else if (secondPoint == -1) {
                nums1[pos--] = nums1[firstPoint--];
            } else if (nums1[firstPoint] > nums2[secondPoint]) {
                nums1[pos--] = nums1[firstPoint--];
            } else {
                nums1[pos--] = nums2[secondPoint--];
            }
        }
    }
};
