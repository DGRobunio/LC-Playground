#include "includes.h"

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = -1;

        string plusSharp = "#";
        for (char ch: s) {
            plusSharp += ch;
            plusSharp += '#';
        }
        plusSharp += '#';
        s = plusSharp;

        vector<int> armLength;
        int rightMark = -1, j = -1;
        for (int i = 0; i < s.size(); i++) {
            int currentArmLength;
            if (rightMark >= i) {
                int mirrorI = j * 2 - i;
                int minimalArmLength = min(armLength[mirrorI], rightMark - i);
                currentArmLength = expand(s, i - minimalArmLength, i + minimalArmLength);
            } else {
                currentArmLength = expand(s, i, i);
            }
            armLength.emplace_back(currentArmLength);

            if (i + currentArmLength > rightMark) {
                j = i;
                rightMark = i + currentArmLength;
            }

            if (currentArmLength * 2 + 1 > end - start) {
                start = i -currentArmLength;
                end = i + currentArmLength;
            }
        }

        string result;
        for (int i = start; i <= end; i++) {
            if (s[i] != '#') {
                result += s[i];
            }
        }
        return result;

    }

private:
    int expand(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return (right - left - 2) / 2;
    }
};
