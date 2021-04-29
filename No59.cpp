//
// Created by zhang on 21/4/29.
//

#include "includes.h"

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0, top = 0;
        int right = n - 1, bottom = n - 1;
        int element = 1;
        vector<vector<int>> result(n,vector<int>(n));
        while (element <= n * n) {
            for (int i = left; i <= right; i++) {
                result[top][i] = element++;
            }
            top++;
            for (int i = top; i <= bottom; i++) {
                result[i][right] = element++;
            }
            right--;
            for (int i = right; i >= left; i--) {
                result[bottom][i] = element++;
            }
            bottom--;
            for (int i = bottom; i >= top; i--) {
                result[i][left] = element++;
            }
            left++;
        }
        return result;
    }
};
