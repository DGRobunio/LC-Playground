//
// Created by zhang on 21/4/28.
//

#include "includes.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1[0] == '0' || num2[0] == '0') {
            return "0";
        }
        int len1 = num1.size(), len2 = num2.size();
        vector<int> resultBuffer;
        string result = "";
        for (int i = len1 - 1; i >=0; i--) {
            int base = len1 - i - 1;
            for (int j = len2 - 1; j >=0; j--) {
                int shift = len2 - 1 - j;
                int temp = (num1[i] - '0') * (num2[j] - '0');
                if (resultBuffer.size() <= base + shift) {
                    resultBuffer.emplace_back(temp);
                } else {
                    resultBuffer[base + shift] += temp;
                }
            }
        }
        for (int i = 0; i < resultBuffer.size(); i++) {
            int temp = resultBuffer[i], pos = i + 1;
            resultBuffer[i] = temp % 10;
            temp /= 10;
            while (temp) {
                if (pos >= resultBuffer.size()) {
                    resultBuffer.emplace_back(temp % 10);
                    pos++;
                } else {
                    resultBuffer[pos++] += temp % 10;
                }
                temp /= 10;
            }
        }
        for (int i = resultBuffer.size() - 1; i >= 0; i--) {
            result+= resultBuffer[i] + '0';
        }
        return result;
    }
};