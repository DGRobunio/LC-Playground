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

    TreeNode* prevNode;

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* result = new TreeNode();
        prevNode = result;
        inOrder(root);
        return result->right;
    }

    void inOrder(TreeNode* node) {
        if (node == nullptr)
            return;
        inOrder(node->left);
        node->left = nullptr;
        prevNode->right = node;
        prevNode = node;
        inOrder(node->right);
    }
};
