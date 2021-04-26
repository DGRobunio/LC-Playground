//
// Created by zhang on 21/4/26.
//

#include "includes.h"

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> charMap = {
                {')','('},
                {']','['},
                {'}','{'}
        };
        vector<char> stack;
        for (char ch: s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                stack.emplace_back(ch);
            } else {
                if (stack.empty())
                    return false;
                char lastChar = *stack.rbegin();
                if (lastChar != charMap[ch]) {
                    return false;
                } else {
                    stack.pop_back();
                }
            }
        }
        if (stack.empty())
            return true;
        else
            return false;
    }
};