/**
 * Title:  Convert BST to Greater Tree (Leetcode Medium)
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
private:
    int cur_sum = 0;
public:
    void transfer(TreeNode *root) {
        if (root == nullptr) return;
        if (root->right) transfer(root->right);
        root->val = (cur_sum += root->val);
        
        if (root->left) transfer(root->left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        transfer(root);
        return root;
    }
};
