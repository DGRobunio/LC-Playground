//
// Created by zhang on 21/5/17.
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
private:
    bool findX = false, findY = false, sameFather = false;
    TreeNode *fatherX = nullptr, *fatherY = nullptr;
    int depthX, depthY;

    void judge(TreeNode* node, TreeNode* parent, int depth, int x, int y) {
        if (node->val == x) {
            fatherX = parent;
            findX = true;
            depthX = depth;
        } else if (node->val == y) {
            fatherY = parent;
            findY = true;
            depthY = depth;
        }
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        judge(root, nullptr, 0, x, y);
        while (!q.empty()) {
            auto&& [node, depth] = q.front();
            if (node->left) {
                q.emplace(node->left, depth + 1);
                judge(node->left, node, depth + 1, x, y);
            }
            if (node->right) {
                q.emplace(node->right, depth + 1);
                judge(node->right, node, depth + 1, x, y);
            }
            if (findX && findY) {
                break;
            }
            q.pop();
        }

        return depthX == depthY && fatherX != fatherY && findX && findY;
    }
};
