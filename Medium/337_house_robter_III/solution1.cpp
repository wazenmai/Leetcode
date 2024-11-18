/**
 * Title:  House Robber III (Leetcode Medium 337)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, November, 2024
 * Method: DP. dp[root][0] = maximum money the thief can rob and he did NOT rob the root. dp[root][1] = maximum money the thief can rob and he rob the root.
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
    pair<int, int> dp(TreeNode* root) {
        if (root == nullptr) return make_pair(0, 0);
        auto left = dp(root->left);
        auto right = dp(root->right);
        pair<int, int> money;
        money.first = max(left.first, left.second) + max(right.first, right.second);
        money.second = left.first + right.first + root->val;
        return money;
    }
    int rob(TreeNode* root) {
        auto money = dp(root);
        return max(money.first, money.second);
    }
};

// df[root][0] = maximum money the thief can rob and he did NOT rob the root
// df[root][1] = maximum money the thief can rob and he rob the root


