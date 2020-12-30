//
// Created by zhang on 20/12/29.
//
#include "includes.h"


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//快慢指针
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }

        ListNode* frontEnd = findMidListNode(head);
        ListNode* endP = reverseHalfListNode(frontEnd->next);
        ListNode* frontP = head;
        while (frontP != nullptr && endP != nullptr) {
            if(frontP->val != endP->val) {
                return false;
            }
            frontP = frontP->next;
            endP = endP->next;
        }
        return true;
    }

    ListNode* reverseHalfListNode(ListNode* originHead) {
        ListNode* currentPointer = nullptr, * prevPointer = nullptr, * tempPointer = nullptr;
        currentPointer = originHead;
        prevPointer = nullptr;

        while (currentPointer != nullptr) {
            tempPointer = currentPointer->next;
            currentPointer->next = prevPointer;
            prevPointer = currentPointer;
            currentPointer = tempPointer;
        }
        return prevPointer;
    }

    ListNode* findMidListNode(ListNode* head) {
        ListNode* slowP = head, * fastP = head;
        while (slowP->next != nullptr && fastP->next != nullptr && fastP->next->next != nullptr) {
            slowP = slowP->next;
            fastP = fastP->next->next;
        }
        return slowP;
    }
};
