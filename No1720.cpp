//
// Created by zhang on 21/5/6.
//

#include "includes.h"

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> result;
        result.emplace_back(first);
        for (auto num: encoded) {
            first = num xor first;
            result.emplace_back(first);
        }
        return result;
    }
};
