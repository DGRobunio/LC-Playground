//
// Created by zhang on 21/1/19.
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

struct NodeReturn {
    int max;
    int min;
    bool isBalanced;
    bool isNull;
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return checkBST(root).isBalanced;
    }

    NodeReturn checkBST(TreeNode* node) {
        NodeReturn returnVal;
        returnVal.max = INT_MIN;
        returnVal.min = INT_MAX;
        returnVal.isBalanced = true;
        returnVal.isNull = false;
        if (node == nullptr) {
            returnVal.isNull = true;
            return returnVal;
        }


        NodeReturn left = checkBST(node->left);
        NodeReturn right = checkBST(node->right);
        if (!left.isBalanced || !right.isBalanced) {
            returnVal.isBalanced = false;
            return returnVal;
        }
        if (left.isNull) {
            returnVal.min = node->val;
        } else {
            if (left.max < node->val) {
                returnVal.min = left.min;
            } else {
                returnVal.isBalanced = false;
            }
        }
        if (right.isNull) {
            returnVal.max = node->val;
        } else {
            if (right.min > node->val) {
                returnVal.max = right.max;
            } else {
                returnVal.isBalanced = false;
            }
        }

        return returnVal;
    }
};