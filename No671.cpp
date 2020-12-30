//
// Created by zhang on 20/12/30.
//

#include "includes.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        return findValueLargerThanRoot(root, root->val);
    }

    int findValueLargerThanRoot(TreeNode* node, int rootVal) {
        if (node == nullptr) {
            return -1;
        }

        if (node->val > rootVal) {
            return node->val;
        }

        int leftVal = findValueLargerThanRoot(node->left, rootVal);
        int rightVal = findValueLargerThanRoot(node->right, rootVal);
        if (leftVal > rootVal && rightVal > rootVal) {
            return min(leftVal, rightVal);
        } else {
            return max(leftVal, rightVal);
        }

    }
};