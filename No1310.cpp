//
// Created by zhang on 21/5/12.
//

#include "includes.h"

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> result(queries.size(), 0);
        vector<int> xorResult(arr.size() + 1);
        for (int i = 0; i < arr.size(); i++) {
            xorResult[i + 1] =xorResult[i] ^ arr[i];
        }
        for (int i = 0; i < queries.size(); i++) {
            result[i] = xorResult[queries[i][0]] ^ xorResult[queries[i][1] + 1];
        }
        return result;
    }
};
