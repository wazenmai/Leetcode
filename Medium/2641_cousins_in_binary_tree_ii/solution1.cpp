/**
 * Title:  Cousins in Binary Tree II(Leetcode Medium 2641)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, October, 2024
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
    int findcousin(TreeNode* root, int level) {
        if (root == nullptr) return 0;
        int left = findcousin(root->left, level + 1);
        int right = findcousin(root->right, level + 1);
        int s = left + right;
        if (s > 0) {
            modify(root->left, s, level + 1);
            modify(root->right, s, level + 1);
        }
        return root->val;
    }
    void modify(TreeNode* root, int val, int level) {
        if (root == nullptr) return;
        // cout << "modify level" << level << ", " << root->val << ", minus " << val << "\n";
        root->val = v[level] - val;
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        // Step 1. Compute level sum
        dfs(root, 0);
        // Step 2. Modify values by first aggregate child sum to parent, then modify children from parent v[level + 1] - sum
        findcousin(root, 0);
        // Modify root value
        root->val = 0;
        return root;
    }
};
