/**
 * Title:  Increasing Order Search Tree (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, April, 2022
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
    TreeNode* inorderBST(TreeNode* root, TreeNode* tail) {
        if (root == nullptr)
            return tail;
        TreeNode* res = inorderBST(root->left, root);
        root->left = nullptr;
        root->right = inorderBST(root->right, tail);
        return res;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        return inorderBST(root, nullptr);
    }
};
