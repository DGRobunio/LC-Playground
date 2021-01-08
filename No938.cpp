//
// Created by zhang on 21/1/8.
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

    int result = 0;

    int rangeSumBST(TreeNode* root, int low, int high) {
        calcBST(root, low, high);
        return result;
    }

    void calcBST(TreeNode* node, int low, int high) {
        if (node == nullptr)
            return;
        calcBST(node->left, low, high);
        if (node->val >= low && node->val <= high)
            result += node->val;
        calcBST(node->right, low, high);
    }
};