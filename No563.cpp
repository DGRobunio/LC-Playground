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
    int tilt;
    int tiltSum;
    int sum;
};

class Solution {
public:
    int findTilt(TreeNode* root) {
        return checkTilt(root).tiltSum;
    }

    ReturnNode checkTilt(TreeNode* root) {
        ReturnNode returnNode;
        returnNode.tilt = 0;
        returnNode.tiltSum = 0;
        returnNode.sum = 0;
        if (root == nullptr) {
            return returnNode;
        }

        ReturnNode left = checkTilt(root->left);
        ReturnNode right = checkTilt(root->right);

        returnNode.tilt = abs(left.sum - right.sum);
        returnNode.tiltSum = returnNode.tilt + left.tiltSum + right.tiltSum;
        returnNode.sum = root->val + left.sum + right.sum;

        return returnNode;

    }

};
