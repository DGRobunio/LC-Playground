//
// Created by zhang on 21/5/14.
//

#include "includes.h"

class Solution {
public:
    string intToRoman(int num) {
        const pair<int, string> dic[] = {
                {1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},
                {100,"C"},{90,"XC"},{50,"L"},{40,"XL"},
                {10,"X"},{9,"IX"},{5,"V"},{4,"IV"},
                {1,"I"},
        };
        string result;
        while(num) {
            for (auto [v, str]: dic) {
                if (num >= v) {
                    num -= v;
                    result+=str;
                    break;
                }
            }
        }
        return result;
    }
};
