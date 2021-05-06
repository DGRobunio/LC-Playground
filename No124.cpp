//
// Created by zhang on 21/5/6.
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
    int result = INT_MIN;
    int maxPart(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftSum = max(maxPart(node->left), 0);
        int rightSum = max(maxPart(node->right), 0);

        int tempResult = node->val + leftSum + rightSum;
        result = max(result, tempResult);

        return node->val + max(leftSum, rightSum);

    }
public:
    int maxPathSum(TreeNode* root) {
        maxPart(root);
        return result;
    }

};