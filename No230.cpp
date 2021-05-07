//
// Created by zhang on 21/5/7.
//

#include "includes.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(-1), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    stack<TreeNode*> stack;
public:
    int kthSmallest(TreeNode* root, int k) {
        while (true) {
            while(root) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if (--k == 0)
                return root->val;
            root = root->right;
        }
    }
};