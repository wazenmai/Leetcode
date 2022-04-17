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
private:
    vector<int> v;
public:
    void find_sort(TreeNode* root) {
        if (root == nullptr) return;
        find_sort(root->left);
        v.emplace_back(root->val);
        find_sort(root->right);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        find_sort(root);
        TreeNode* ans = new TreeNode(v[0]);
        TreeNode* cur = ans;
        int n = (int)v.size();
        for (int i = 1; i < n; i++) {
            cur->right = new TreeNode(v[i]);
            cur = cur->right;
        }
        return ans;
    }
};
