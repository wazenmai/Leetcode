/**
 * Title:  Sum of Root to Leaf Binary Numbers (Leetcode Easy 1022)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, Jan, 2022
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
    int ans;
public:
    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        dfs(root, 0, 0);
        return ans;
    }
    
    void dfs(TreeNode*root, int pre, int level) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr) {
            ans += pre * 2 + root->val;
            return;
        }
        dfs(root->left, pre * 2 + root->val, level + 1);
        dfs(root->right, pre * 2 + root->val, level + 1);
    }
};
