/**
 * Title:  Binary Tree Inorder Traversal (Leetcode Easy 94)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   09, December, 2023
 * Method: Morris method, move all the left subtree to the rightmost node of the left subtree
 * Result: Time complexity O(n), Because a binary Tree with nnn nodes has n−1 edges, the whole processing for each edges up to 2 times, one is to locate a node, and the other is to find the predecessor node. So the complexity is O(n).
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
        /* Morris Method */
        TreeNode* cur = root;
        TreeNode* pre = cur;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                ans.emplace_back(cur->val);
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right != nullptr) { // find the rightmost node in left subtree
                    pre = pre->right;
                }
                pre->right = cur;
                TreeNode* temp = cur;
                cur = cur->left;
                temp->left = nullptr;
            }
        }
        return ans;
    }
};