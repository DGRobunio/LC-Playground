//
// Created by zhang on 20/12/29.
//
#include "includes.h"
/*
 * 划分数组
 * *在统计中，中位数用来将一个集合划分成两个长度相等的子集，其中一个子集中的元素总是大于另一个子集中的元素*
 * 在任意位置 i 将A划分为两个部分 leftA & rightA
 * 同样地，在任意位置 j 将B划分为两个部分 leftB & rightB
 * 令left = leftA + leftB, right = rightA + rightB
 * 那么根据中位数定义 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //需要假定nums1长度小于nums2，所以当不符合条件时进行数组对调
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        // nums1 = A; nums2 = B
        int sizeA = nums1.size();
        int sizeB = nums2.size();
        //为了在 [0,m] 中寻找最大的 i ，使得 A[i-1] <= B[j], 其中 j=(m+n+1)/2-i
        //二分法查找最大的i，定义 left 和 right
        int left = 0, right = sizeA;
        int leftMax = 0, rightMin = 0;

        while (left <= right) {
            int i = (left + right) / 2;
            int j = (sizeA + sizeB + 1) / 2 - i;

            // nums1[i-1]
            int num_iMinusOne = (i==0? INT_MIN : nums1[i-1]);
            // nums1[i]
            int num_i = (i == sizeA? INT_MAX: nums1[i]);
            // nums2[j-1]
            int num_jMinusOne = (j==0? INT_MIN : nums2[j-1]);
            // nums2[j]
            int num_j = (j == sizeB? INT_MAX: nums2[j]);

            //核心判定：在 [0, m] 中寻找最大的i，使得 A[i-1] <= B[j], 其中 j=(m+n+1)/2-i
            if ( num_iMinusOne <= num_j) {
                leftMax = max(num_iMinusOne, num_jMinusOne);
                rightMin = min(num_i, num_j);
                left = i + 1;
            } else {
                right = i - 1;
            }
        }

        return (sizeA + sizeB) % 2 == 0? (leftMax + rightMin) / 2.0 : leftMax;
    }
};

