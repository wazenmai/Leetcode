/**
 * Title:  Diameter of Binary Tree (Leetcode Easy 543)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, February, 2024
 * Method: Use a recursive function to check the height of each node. In the recursive function, calculate the height of left and right subtree, and update the diameter if necessary.
 * Result: Time Complexity: O(n). Space Complexity: O(n).
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
    int diameter;
    int checkHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        int l = checkHeight(root->left);
        int r = checkHeight(root->right);
        diameter = max(diameter, l + r);
        // cout << "check " << root->val << ", diameter: " << diameter << "\n";
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        int l = checkHeight(root->left);
        int r = checkHeight(root->right);
        diameter = max(diameter, l + r);
        // cout << "check " << root->val << ", diameter: " << diameter << "\n";
        return diameter;
    }
};
