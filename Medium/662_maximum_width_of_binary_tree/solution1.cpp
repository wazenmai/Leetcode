/**
 * Title:  Maximum Width of Binary Tree(Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, Feb, 2022
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
    int widthOfBinaryTree(TreeNode* root) {
        root->val = 1;
        queue<TreeNode*> q;
        q.push(root);
        int nodes = 1;
        int maxWidth = 1;
        int left = 2147483647;
        int right = 0;
        int shift = 0;
        while (nodes--) {
            TreeNode* temp = q.front();
            temp->val = temp->val - shift;
            q.pop();
            if (temp->val < left)
                left = temp->val;
            if (temp->val > right)
                right = temp->val;
            if (temp->left != nullptr) {
                temp->left->val = (temp->val << 1) - 1;
                q.push(temp->left);
            }
            if (temp->right != nullptr) {
                temp->right->val = (temp->val << 1);
                q.push(temp->right);
            }
            if (nodes == 0) {
                maxWidth = max(maxWidth, right - left + 1);
                nodes = q.size();
                if (q.size() != 0) {
                    shift = q.front()->val - 1;
                }
                left = 2147483647;
                right = 0;
            }
        }
        return maxWidth;
    }
};
