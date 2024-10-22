/**
 * Title:  Kth Largest Sum in a Binary Tree (Leetcode Medium 2583)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, October, 2024
 * Result: Time complexity O(n + hlogh). Space complexity O(n + h). n is the number of nodes, h is the height of the tree.
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
    vector<long long> v;
public:
    void dfs(TreeNode* root, int level) {
        if (root == nullptr) return;
        if (v.size() == level) {
            v.emplace_back(root->val);
        } else {
            v[level] += root->val;
        }
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        dfs(root, 0);
        sort(v.begin(), v.end(), greater<long long>());
        if (k > v.size()) return -1;
        return v[k - 1];
    }
};
