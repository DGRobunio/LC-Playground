//
// Created by zhang on 21/5/7.
//

#include "includes.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
class Solution {
private:
    unordered_map<TreeNode*, TreeNode*> fatherMap;
    unordered_map<TreeNode*, bool>isVisited;
    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        isVisited[node] = false;
        dfs(node->left);
        if (node->left) {
            fatherMap[node->left] = node;
        }
        if (node->right) {
            fatherMap[node->right] = node;
        }
        dfs(node->right);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root);
        fatherMap[root] = nullptr;
        while (p) {
            isVisited[p] = true;
            p = fatherMap[p];
        }
        while (q) {
            if (isVisited[q])
                return q;
            q = fatherMap[q];
        }
        return root;
    }
};
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return root;
        if (root == p || root == q)
            return root;
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr)
            return root;
        if (left != nullptr)
            return left;
        if (right != nullptr)
            return right;
        return nullptr;
    }
};