//
// Created by zhang on 21/1/8.
//

#include "includes.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:

    int prevValue = INT_MAX;
    int result = INT_MAX;

    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return result;
    }

    void dfs(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        dfs(root->left);
        result = min(result, abs(root->val - prevValue));
        prevValue = root->val;
        dfs(root->right);
    }
};