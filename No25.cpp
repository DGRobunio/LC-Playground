//
// Created by zhang on 21/5/7.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        auto nextGroupNode = head;
        auto currentNode = dummyHead;
        while (nextGroupNode) {
            ListNode* reverseNode = nextGroupNode;
            nextGroupNode = cutNode(reverseNode, k);
            if (reverseNode == nextGroupNode) {
                currentNode->next = reverseNode;
                auto result = dummyHead->next;
                delete dummyHead;
                return result;
            }
            reverseNode = reverseGroupNode(reverseNode);
            currentNode->next = reverseNode;
            while (reverseNode->next) {
                reverseNode = reverseNode->next;
            }
            currentNode = reverseNode;
        }
        auto result = dummyHead->next;
        delete dummyHead;
        return result;
    }

private:
    ListNode* reverseGroupNode(ListNode* head) {
        auto current = head;
        ListNode* prev = nullptr;
        while (current) {
            auto next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    ListNode* cutNode(ListNode* head, int step) {
        ListNode* p = head;
        while (p && --step) {
            p = p->next;
        }

        if (step)
            return head;

        auto next = p->next;
        p->next = nullptr;
        return next;
    }
};

