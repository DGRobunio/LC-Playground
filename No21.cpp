//
// Created by zhang on 20/12/29.
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
//    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//        ListNode *lp1 = l1, *lp2 = l2, *result = nullptr, *p = nullptr;
//        if (lp1 == nullptr)
//            return lp2;
//        if (lp2 == nullptr)
//            return lp1;
//        if (lp1->val < lp2->val) {
//            result = lp1;
//            lp1 = lp1->next;
//        } else {
//            result = lp2;
//            lp2 = lp2->next;
//        }
//        p = result;
//        while (lp1 != nullptr && lp2 != nullptr) {
//            if (lp1->val < lp2->val) {
//                p->next = lp1;
//                lp1 = lp1->next;
//            } else {
//                p->next = lp2;
//                lp2 = lp2->next;
//            }
//            p = p->next;
//        }
//        if (lp1 == nullptr)
//            p->next = lp2;
//        if (lp2 == nullptr)
//            p->next = lp1;
//        return result;
//    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};