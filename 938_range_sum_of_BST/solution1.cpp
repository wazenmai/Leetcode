/**
 * Title:  Range Sum of BST (Leetcode Easy 938)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, Dec, 2021
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr)
            return 0;

        int answer = 0;

        if (root->val >= low && root->val <= high) {
            answer += root->val;
            answer += (root->val != low) ? rangeSumBST(root->left, low, high) : 0;
            answer += (root->val != high) ? rangeSumBST(root->right, low, high) : 0;
        } else if (root->val > low) { // only go left
            answer += rangeSumBST(root->left, low, high);
        } else if (root->val < high) {
            answer += rangeSumBST(root->right, low, high);
        }

        return answer;
    }
};

