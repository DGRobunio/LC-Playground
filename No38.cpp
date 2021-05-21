//
// Created by zhang on 21/5/20.
//

#include "includes.h"

class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
        string result = "1";
        string temp;
        while (--n) {
            temp.clear();
            auto it = result.begin();
            while (it < result.end()) {
                int count = 1;
                char key = *it;
                while (*(++it) == key) count++;
                temp += (count + '0');
                temp += key;
            }
            result = temp;
        }
        return result;
    }
};
