/**
 * Title:  Binary Tree Maximum Path Sum (Leetcode Hard 124)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, November, 2024
 * Method: Every node pass the maximum path sum that can pass upward and cannot pass upward.
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
    pair<int, int> compute_path(TreeNode* root) { // pass me, no pass upward
        if (root == nullptr) return make_pair(-1000, -1000);
        auto left = compute_path(root->left);
        auto right = compute_path(root->right);
        // 6 condition: only root, left no, right no, left-root-right, left-root, right-root
        int no_pass_up = max(root->val, max(left.first + root->val + right.first, max(left.second, right.second)));
        no_pass_up = max(no_pass_up, max(left.first + root->val, right.first + root->val)); 
        // 3 condition: only root, left-root, right-root
        int pass_up = max(root->val, max(left.first + root->val, right.first + root->val));
        // cout << root->val << ": " << pass_up << ", " << no_pass_up << "\n";
        return make_pair(pass_up, no_pass_up);
    }
    int maxPathSum(TreeNode* root) {
        auto path_sum = compute_path(root);
        return max(path_sum.first, path_sum.second);
    }
};
