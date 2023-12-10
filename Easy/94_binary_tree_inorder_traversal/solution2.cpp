/**
 * Title:  Binary Tree Inorder Traversal (Leetcode Easy 94)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   09, December, 2023
 * Method: Use stack to store the middle value and go left first, then go right and pop the stack value.
 * Result: Time complexity O(n)
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != nullptr || !st.empty()) {
            while (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top();
            st.pop();
            ans.emplace_back(cur->val);
            cur = cur->right;
        }
        return ans;
    }
};