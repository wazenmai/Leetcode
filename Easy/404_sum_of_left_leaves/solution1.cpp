/**
 * Title:  Sum of Left Leaves (Leetcode Easy 404)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, April, 2024
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
    int computeLeft(TreeNode* root, int dir) {
        if (root == nullptr) return 0;
        if (dir == 0 && root->left == nullptr && root->right == nullptr) {
            return root->val;
        }
        return computeLeft(root->left, 0) + computeLeft(root->right, 1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return computeLeft(root, 1);
    }
};
