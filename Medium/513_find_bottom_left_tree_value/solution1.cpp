/**
 * Title:  Find Bottom Left Tree Value (Leetcode Medium 513)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, February, 2024
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
    int bottom;
    int ans;
    void findValue(TreeNode* root, int level) {
        if (root == nullptr) return;
        if (level > bottom) {
            bottom = level;
            ans = root->val;
        }
        if (root->left) findValue(root->left, level + 1);
        if (root->right) findValue(root->right, level + 1);
    }
    int findBottomLeftValue(TreeNode* root) {
        bottom = 0;
        ans = root->val;
        findValue(root, 0);
        return ans;
    }
};
