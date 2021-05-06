//
// Created by zhang on 21/5/6.
//

#include "includes.h"

class Solution {
public:
    string reverseWords(string s) {
        if (s.size() < 2) return s;
        vector<int> left, right;
        left.emplace_back(0);
        int temp = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                right.emplace_back(temp - 1);
                left.emplace_back(temp + 1);
            }
            temp++;
        }
        right.emplace_back(s.size() - 1);
        string result;
        for (int i = 0; i < left.size(); i++) {
            for (int j = right[i]; j >= left[i]; j--) {
                result+=s[j];
            }
            result+=' ';
        }
        result.erase(result.end() - 1);
        return result;
    }
};
