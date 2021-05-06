//
// Created by zhang on 21/5/6.
//

#include "includes.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA, *pB;
        pA = headA, pB= headB;
        bool isLooping = true;
        while (pA != pB) {
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
            if (pA == headB && pB == headA) {
                isLooping = !isLooping;
                if (isLooping)
                    return nullptr;
            }
        }
        return pA;
    }
};
