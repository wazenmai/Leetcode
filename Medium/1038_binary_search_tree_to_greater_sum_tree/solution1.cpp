/**
 * Title:  Binary Search Tree to Greater Sum Tree (Leetcode Medium 1038)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, June, 2024
 * Method: Traverse from right -> left -> root, pass the parent add to each child node, the ans need to return is lsum + rsum + root->val, and the value of root need to be updated to root->val + rsum + add.
 * Result: Time complexity is O(n), space complexity is O(1).
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
    int traverse(TreeNode* root, int add) {
        if (root == nullptr) return 0;
        int rsum = traverse(root->right, add);
        int lsum = traverse(root->left, add + root->val + rsum);
        int ans = rsum + lsum + root->val;
        root->val += rsum + add;
        return ans;
    }
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root, 0);
        return root;
    }
};
