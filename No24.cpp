//
// Created by zhang on 21/1/18.
//

#include "includes.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* current = head;
        if (current == nullptr || current->next == nullptr) {
            return current;
        }
        ListNode* newHead = current->next;
        current->next = swapPairs(newHead->next);
        newHead->next = current;
        return (newHead);
    }
};