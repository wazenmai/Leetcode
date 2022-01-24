/**
 * Title:  Insert into a Binary Search Tree (Leetcode Medium 701)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, Jan, 2022
 * Result: Accepted, faster than solution1
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
            return new TreeNode(val);
        
        TreeNode* cur = root;
        TreeNode* temp;
        char direction;
        while (cur != nullptr) {
            temp = cur;
            if (val < cur->val) {
                direction = '0';
                cur = cur->left;
            } else {
                direction = '1';
                cur = cur->right;
            }
        }
        if (direction == '1')
            temp->right = new TreeNode(val);
        else
            temp->left = new TreeNode(val);
        return root;
    }
};
