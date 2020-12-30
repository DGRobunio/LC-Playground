//
// Created by zhang on 20/12/30.
//

#include "includes.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        vector<string> result;
        if(digits.empty()) {
            return result;
        }

//        initialize phonePad
        unordered_map<char, string> phonePad{
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
        };

        string combination;
        appendLetterCombinations(result, phonePad, digits, 0, combination);
        return result;

    }

    void appendLetterCombinations(vector<string>& result,
                                  const unordered_map<char,
                                  string>& phonePad,
                                  const string& digits,
                                  int index,
                                  string combination) {
        if (index == digits.length()) {
            result.push_back(combination);
        } else {
            char digit = digits[index];
            const string& letters = phonePad.at(digit);
            for (const char& letter: letters) {
                combination.push_back(letter);
                appendLetterCombinations(result, phonePad, digits, index + 1, combination);
                combination.pop_back();
            }
        }
    }
};