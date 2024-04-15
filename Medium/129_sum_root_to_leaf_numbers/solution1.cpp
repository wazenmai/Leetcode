/**
 * Title: Sum Root to Leaf Numbers (Leetcode Medium 129)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, April, 2024
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countSum(TreeNode* root, int num) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr) {
            return num * 10 + root->val;
        }
        num = num * 10 + root->val;
        return countSum(root->left, num) + countSum(root->right, num);
    }
    int sumNumbers(TreeNode* root) {
        return countSum(root, 0);
    }
};
