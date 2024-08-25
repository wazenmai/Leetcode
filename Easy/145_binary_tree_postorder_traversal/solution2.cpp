/**
 * Title:  Binary Tree Postorder Traversal (Leetcode Easy 145)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, August, 2024
 * Method: Iterative version. Record answer in reverse order.
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> parent;
        TreeNode* cur = root;
        while (cur != nullptr || !parent.empty()) {
            if (cur != nullptr) {
                ans.emplace_back(cur->val);
                parent.push(cur);
                cur = cur->right;
            } else {
                cur = parent.top();
                parent.pop();
                cur = cur->left;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
