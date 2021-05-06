//
// Created by zhang on 21/5/6.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        findCommonAncestor(root, p->val, q->val);
        return result;
    }

    void findCommonAncestor(TreeNode* root, int p, int q) {
        int val = root->val;
        if ((val - p) * (val - q) <= 0) {
            result = root;
        } else if (p < val && q < val) {
            findCommonAncestor(root->left, p, q);
        } else if (p > val && q > val) {
            findCommonAncestor(root->right, p, q);
        }
    }

private:
    TreeNode *result;
};
