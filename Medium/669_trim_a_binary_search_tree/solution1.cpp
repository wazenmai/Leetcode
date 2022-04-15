/**
 * Title:  Trim a Binary Search Tree (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, April, 2022
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // cout << "trimBST ";
        if (root == nullptr) {
            // cout << "null\n";
            return nullptr;
        }
        if (root->right == nullptr && root->left == nullptr) {
            if (root->val < low || root->val > high) {
                // cout << root->val << " delete\n";
                return nullptr;
            }
            // cout << root->val << " save\n";
            return root;
        }
        if (root->val < low) {
            // cout << root->val << " find right\n";
            return trimBST(root->right, low, high);
        }
        if (root->val > high) {
            // cout << root->val << " find left\n";
            return trimBST(root->left, low, high);
        }
        // cout << root->val << " find both\n";
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
