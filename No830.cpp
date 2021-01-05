//
// Created by zhang on 21/1/5.
//

#include "includes.h"

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> result;

        if (s.empty()) {
            return result;
        }

        char nowChar = s[0];
        int left = 0, right = 0;

        for (int i =1; i < s.length(); i++) {
            if (s[i] == nowChar) {
                right++;
            } else {
                if (right - left >= 2) {
                    vector<int> temp;
                    temp.emplace_back(left);
                    temp.emplace_back(right);
                    result.emplace_back(temp);
                }

                left = i;
                right = left;
                nowChar = s[i];
            }
        }

        if (right - left >= 2) {
            vector<int> temp;
            temp.emplace_back(left);
            temp.emplace_back(right);
            result.emplace_back(temp);
        }

        return result;

    }
};