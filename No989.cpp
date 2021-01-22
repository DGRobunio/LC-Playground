//
// Created by zhang on 21/1/22.
//
#include "includes.h"

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int carry = 0;
        if (K == 0)
            return A;
        vector<int> B;
        while (K) {
            B.insert(B.begin(),K % 10);
            K /= 10;
        }
        if (B.size() > A.size()) {
            swap(A, B);
        }
        auto itA = A.end() - 1, itB = B.end() - 1;
        while (itB != B.begin() - 1) {
            *itA += carry + *itB;
            carry = *itA / 10;
            *itA = *itA % 10;
            itB--;
            itA--;
        }
        while (carry) {
            if (itA >= A.begin() {
                *itA++;
                carry = *itA / 10;
                *itA = *itA % 10;
            } else {
                A.insert(A.begin(), carry);
                break;
            }
        }
        return A;
    }
};
