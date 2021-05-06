//
// Created by zhang on 21/5/6.
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
    ListNode* sortList(ListNode* head) {
        int size = 0;
        ListNode *p = head;
        ListNode *dummyHead = new ListNode();
        dummyHead->next = head;
        while (p != nullptr) {
            size++;
            p = p->next;
        }
        for (int subLength = 1; subLength < size; subLength <<= 1) {
            auto currentNode = dummyHead->next;
            auto tailNode = dummyHead;

            while (currentNode) {
                auto leftList = currentNode;
                auto rightList = cutNode(leftList, subLength);
                currentNode = cutNode(rightList, subLength);

                tailNode->next = merge(leftList, rightList);
                while (tailNode->next) {
                    tailNode = tailNode->next;
                }
            }
        }
        auto result = dummyHead->next;
        delete dummyHead;
        return result;
    }

private:
    ListNode* cutNode(ListNode* head, int step) {
        auto p = head;
        while (p && --step) {
            p = p->next;
        }
        if (!p) return nullptr;
        auto nextNode = p->next;
        p->next = nullptr;
        return nextNode;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummyHead = new ListNode();
        auto p = dummyHead;
        while(left && right) {
            if (left->val > right->val) {
                p->next = left;
                p = left;
                left = left->next;
            } else {
                p->next = right;
                p = right;
                right = right->next;
            }
        }
        p->next = left? left: right;
        p = dummyHead->next;
        delete dummyHead;
        return p;
    }
};
