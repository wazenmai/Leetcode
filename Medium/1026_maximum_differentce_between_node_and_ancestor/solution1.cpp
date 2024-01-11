/**
 * Title:  Maximum Difference Between Node and Ancestor (Leetcode Medium 1026)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, Janurary, 2024
 * Method: DFS with vector to store the ancestor.
 * Result: Time complexity: O(n), Space complexity: O(n)
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
    int maxDiff(TreeNode* root, vector<TreeNode*>& v, int ans) {
        if (root == nullptr) return ans;
        for (auto& node: v) {
            ans = max(ans, abs(node->val - root->val));
        }
        v.emplace_back(root);
        int l = maxDiff(root->left, v, ans);
        int r = maxDiff(root->right, v, ans);
        v.pop_back();
        // cout << "At node " << root->val << ", ans: " << ans << "\n"; 
        return max(l, r);
    }
    int maxAncestorDiff(TreeNode* root) {
        vector<TreeNode*> v;
        return maxDiff(root, v, 0);
    }
};
