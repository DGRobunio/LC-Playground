//
// Created by zhang on 21/5/12.
//

#include "includes.h"

class Solution {
private:
    bool checkGap(vector<int>& pos, int gap, int num) {
        int prev = *(pos.begin());
        int count = 1;
        for (int i = 1; i < pos.size(); i++) {
            if (pos[i] - prev >= gap) {
                count++;
                prev = pos[i];
            }
        }
        return count >= num;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int left = 1, right = *(position.rbegin()) - *(position.begin());
        int result = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (checkGap(position,mid, m)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};
