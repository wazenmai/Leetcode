/**
 * Title:  Add One Row to Tree (Leetcode Medium 623)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, April, 2024
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
    TreeNode* addRow(TreeNode* root, int val, int depth, int level, int from) {
        // from: 0-left, 1-right
        if (level > depth) return root;
        if (level == depth) {
            TreeNode* newNode;
            if (root == nullptr) newNode = new TreeNode(val);
            else if (from == 0) newNode = new TreeNode(val, root, nullptr);
            else newNode = new TreeNode(val, nullptr, root);
            return newNode;
        }
        if (root == nullptr) return root;
        root->left = addRow(root->left, val, depth, level + 1, 0);
        root->right = addRow(root->right, val, depth, level + 1, 1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return addRow(root, val, depth, 1, 0);
    }
};
