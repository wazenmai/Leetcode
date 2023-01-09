/**
 * Title:  Binary Tree Preorder Traversal (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   09, Janurary, 2023
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
    vector<int> v;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        travel(root);
        return v;
    }

    void travel(TreeNode* root) {
        if (root == nullptr)
            return;
        v.emplace_back(root->val);
        travel(root->left);
        travel(root->right);
    }
};
