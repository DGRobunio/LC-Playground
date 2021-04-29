//
// Created by zhang on 21/4/29.
//

#include "includes.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top, bottom, left, right, numCount;
        top = 0;
        bottom = matrix.size() - 1;
        left = 0;
        right = matrix[0].size() - 1;
        numCount = matrix.size() * matrix[0].size();
        vector<int> result;
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right && numCount; i++) {
                result.emplace_back(matrix[top][i]);
                numCount--;
            }
            top++;
            for (int i = top; i <= bottom && numCount; i++) {
                result.emplace_back(matrix[i][right]);
                numCount--;
            }
            right--;
            for (int i = right; i >= left && numCount; i--) {
                result.emplace_back(matrix[bottom][i]);
                numCount--;
            }
            bottom--;
            for (int i = bottom; i >= top && numCount; i--) {
                result.emplace_back(matrix[i][left]);
                numCount--;
            }
            left++;
        }
        return result;
    }
};