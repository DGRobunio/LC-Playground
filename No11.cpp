//
// Created by zhang on 20/12/30.
//

#include "includes.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int h1 = 0;
        int h2 = height.size() - 1;
        int maxArea = 0;
        while(h1 != h2) {
            int area = (h2-h1) * min(height[h1], height[h2]);
            maxArea = max(area, maxArea);
            if (height[h1] < height[h2]) {
                h1++;
            } else {
                h2--;
            }
        }
        return maxArea;
    }
};