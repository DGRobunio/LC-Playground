//
// Created by zhang on 21/1/6.
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

struct ReturnNode {
    bool isBalance;
    int depth;
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkBalanced(root).isBalance;
    }

    ReturnNode checkBalanced(TreeNode* root) {
        ReturnNode returnNode;
        returnNode.depth = 0;
        if (root == nullptr) {
            returnNode.isBalance = true;
            return returnNode;
        }
        ReturnNode left = checkBalanced(root->left);
        ReturnNode right = checkBalanced(root->right);
        if (!left.isBalance || !right.isBalance) {
            returnNode.isBalance = false;
            return returnNode;
        }

        if (abs(left.depth - right.depth) > 1) {
            returnNode.isBalance = false;
            return returnNode;
        }

        returnNode.isBalance = true;
        returnNode.depth = max(left.depth , right.depth) + 1;

        return returnNode;
    }
};