//
// Created by zhang on 21/4/29.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* curr = head->next;
        int count = 0;
        while (curr != head) {
            count++;
            if (curr->next == nullptr) {
                curr->next = head;
            } else {
                curr = curr->next;
            }
        }
        int shift = count - (k % count);
        ListNode* prev = nullptr;
        curr = head;
        while (shift--) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;
        return curr;
    }
};