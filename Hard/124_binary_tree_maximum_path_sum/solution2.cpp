/**
 * Title:  Binary Tree Maximum Path Sum (Leetcode Hard 124)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, November, 2024
 * Method: Instead of passing path-sum that won't be pass upward, we pass ans as a reference argument and update in the function. The answer = max(ans, root->val + left + right), and the value who pass up will be root->val + max(left, right).
 * Result: Time complexity O(n), space complexity O(n). // n is the number of nodes in the tree.
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
    int compute_path(TreeNode* root, int& ans) {
        if (root == nullptr) return 0;
        int left = max(0, compute_path(root->left, ans));
        int right = max(0, compute_path(root->right, ans));
        ans = max(ans, root->val + left + right);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        compute_path(root, ans);
        return ans;
    }
};
