/**
 * Title:  Delete Leaves With a Given Value (Leetcode Medium 1325)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, May, 2024
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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root == nullptr) return root;
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if (root->val == target && root->left == nullptr && root->right == nullptr)
            return nullptr;
        return root;
    }
};
