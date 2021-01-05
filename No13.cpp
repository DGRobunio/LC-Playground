//
// Created by zhang on 21/1/5.
//
#include "includes.h"

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> r2IMap {{'I', 1}, {'V', 5},
                                         {'X', 10}, {'L', 50},
                                         {'C', 100}, {'D', 500},
                                         {'M', 1000}};

        int result = 0;

        for (int i = 0; i < s.length(); i++) {
            if (i != s.length()-1) {
                result += (r2IMap[s[i]] < r2IMap[s[i+1]])? (-1) * r2IMap[s[i]]: r2IMap[s[i]];
            } else {
                result += r2IMap[s[i]];
            }
        }
        return result;
    }
};

