/**
 * Title:  Construct String from Binary Tree (Leetcode Easy 606)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, December, 2023
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
    string tree2str(TreeNode* root) {
        if (root == nullptr) {
            return "()";
        }
        string str = "";
        str += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
          return str;
        if (root->left) {
            str += "(";
            str += tree2str(root->left);
            str += ")";
        } else {
          str += "()";
        }
        if (root->right) {
            str += "(";
            str += tree2str(root->right);
            str += ")";
        }
        return str;
    }
};
