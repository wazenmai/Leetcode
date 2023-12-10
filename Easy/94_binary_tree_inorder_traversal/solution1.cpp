/**
 * Title:  Binary Tree Inorder Traversal (Leetcode Easy 94)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   09, December, 2023
 * Method: Recusion
 * Result: Time complexity O(n)
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
    vector<int> ans;
    void travel(TreeNode* root) {
        if (root == nullptr)
            return;
        travel(root->left);
        ans.emplace_back(root->val);
        travel(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr)
            return ans;
        travel(root);
        return ans;
    }
};
