//
// Created by zhang on 21/4/25.
//
#include "includes.h"

//自动机
//          ' '	    +/-	    number	    other
//start	    start	signed	inNumber	end
//signed	end	    end	    inNumber	end
//inNumber	end	    end	    inNumber	end
//end	    end	    end	    end	        end
class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
            {"start", {"start", "signed", "inNumber", "end"}},
            {"signed", {"end", "end", "inNumber", "end"}},
            {"inNumber", {"end", "end", "inNumber", "end"}},
            {"end", {"end", "end", "end", "end"}}
    };
    int getColumn(char c) {
        if (isspace(c)) return 0;
        if (c == '-' || c == '+') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }

public:
    int sign = 1;
    long long result = 0;
    
    void get(char c) {
        state = table[state][getColumn(c)];
        if (state == "inNumber") {
            result = result * 10 + c - '0';
            result = sign == 1 ? min(result, (long long)INT_MAX) : min(result, -(long long)INT_MIN);
        } else if (state == "signed")
            sign = c == '+' ? 1: -1;
    }
};

class Solution {
public:
    int myAtoi(string s) {
        Automaton automaton;
        for (auto c: s)
            automaton.get(c);
        return automaton.result * automaton.sign;
    }
};

//class Solution {
//public:
//    int myAtoi(string s) {
//        int result = 0, flag = 0;
//        bool startMark = false;
//        for (int i = 0; i < s.size(); i++) {
//            char c = s[i];
//            if (c == ' ' && !startMark)
//                continue;
//            if (c == '-' && flag == 0 && !startMark) {
//                flag = -1;
//                startMark = true;
//                continue;
//            }
//            if (c == '+' && flag == 0 && !startMark) {
//                flag = 1;
//                startMark = true;
//                continue;
//            }
//            if (c < '0' || c > '9') {
//                break;
//            }
//            if (c >= '0' && c <= '9') {
//                startMark = true;
//                int num = c - '0';
//                if (flag == -1) {
//                    if (result > INT_MAX / 10) {
//                        result = INT_MIN;
//                        flag = 1;
//                        break;
//                    } else if (result == INT_MAX / 10 && num >= abs(INT_MIN % 10)) {
//                        result = INT_MIN;
//                        flag = 1;
//                        break;
//                    } else {
//                        result *= 10;
//                        result += num;
//                    }
//                } else {
//                    if (result > INT_MAX / 10) {
//                        result = INT_MAX;
//                        break;
//                    } else if (result == INT_MAX / 10 && num >= INT_MAX % 10) {
//                        result = INT_MAX;
//                        break;
//                    } else {
//                        result *= 10;
//                        result += num;
//                    }
//                }
//            }
//        }
//        if (flag == 0)
//            flag = 1;
//        return result * flag;
//    }
//};