//
// Created by zhang on 21/5/27.
//

#include "includes.h"

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        unordered_map<int, int> countMap;
        if (size1 > size2) {
            swap(nums1, nums2);
            swap(size1,size2);
        }
        for (auto num: nums1) {
            countMap[num]++;
        }
        vector<int> result;
        for (auto num: nums2) {
            if (countMap.find(num) != countMap.end()) {
                result.emplace_back(num);
                countMap[num]--;
                if (countMap[num] == 0) {
                    countMap.erase(num);
                }
            }
        }
        return result;
    }
};
