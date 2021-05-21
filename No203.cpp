//
// Created by zhang on 21/5/20.
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
    ListNode *removeElements(ListNode *head, int val) {
        ListNode* dummyhead = new ListNode();
        dummyhead->next = head;
        ListNode* prevNode = dummyhead;
        ListNode* currentNode = head;
        while (currentNode != nullptr) {
            if (currentNode->val == val) {
                prevNode->next = currentNode->next;
                currentNode = currentNode->next;
            } else {
                prevNode = currentNode;
                currentNode = currentNode->next;
            }
        }
        return dummyhead->next;
    }
};
