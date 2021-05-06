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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
