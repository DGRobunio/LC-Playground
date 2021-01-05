//
// Created by zhang on 21/1/5.
//

#include "includes.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        if (strs.empty()) {
            return result;
        }
        auto minLength = strs[0].length();
        for (auto& str: strs) {
            minLength = min(minLength, str.length());
        }

        for (int i = 0; i < minLength; i++) {
            bool sameChar = true;
            char compareChar = strs[0][i];
            for (auto& str: strs) {
                if (str[i] != compareChar) {
                    sameChar = false;
                    break;
                }
            }
            if (sameChar) {
                result += compareChar;
            } else {
                break;
            }
        }

        return result;

    }
};