//
// Created by zhang on 20/12/29.
//
#include "includes.h"

class Solution {
public:
//    int strStr(string haystack, string needle) {
//        int result = -1;
//        int strLength = haystack.length();
//        if(needle.length() == 0) {
//            return 0;
//        }
//        for (int i = 0; i < strLength ; i++) {
//            if(haystack[i] == needle[0]) {
//                bool findSubString = true;
//                for(int j = needle.length()-1; j > 0; j--) {
//                    if(i+j >= strLength) {
//                        findSubString = false;
//                        break;
//                    }
//                    if(haystack[i+j] != needle[j]) {
//                        findSubString = false;
//                        break;
//                    }
//                }
//                if (findSubString) {
//                    result = i;
//                    break;
//                }
//            }
//        }
//        return result;
//    }
    // hash
    int strStr(string haystack, string needle) {
        int result = -1;
        int strLength = haystack.length();
        int subStrLength = needle.length();
        if(needle.length() == 0) {
            return 0;
        }
        hash<string> hash;
        vector<long> hashVec;
        auto subHash = hash(needle);
        for (int i = 0; i < 1 + strLength - subStrLength; i++) {
            hashVec.push_back(hash(haystack.substr(i,subStrLength)));
        }
        for (int i = 0; i < 1 + strLength - subStrLength; i++) {
            if(hashVec[i] == subHash) {
                bool findSubString = true;
                for(int j = 0; j < subStrLength; j++) {
                    if(haystack[i + j] != needle[j]) {
                        findSubString = false;
                        break;
                    }
                }
                if (findSubString) {
                    result = i;
                    break;
                }
            }
        }
        return result;
    }
};
