/**
 * Title:  Binary Tree Postorder Traversal (Leetcode Easy 145)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, August, 2024
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
private:
    vector<int> ans;
public:
    void travel(TreeNode* root) {
        if (root == nullptr) return;
        travel(root->left);
        travel(root->right);
        ans.emplace_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        travel(root);
        return ans;
    }
};
