/**
 * Title:  Distribute Coins in Binary Tree (Leetcode Medium 979)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, May, 2024
 * Method: Let answer be global variable, and giveCoin be a function that returns the number of coins that the subtree rooted at root should give to its parent. 
 *         The number of moves is the sum of the absolute values of the number of coins that the subtree rooted at root should give to its parent.
 * Result: Time complexity O(n). Space complexity O(h). // n is the number of nodes in the tree, h is the height of the tree.
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
    int moves;
public:
    int giveCoin(TreeNode* root) { // coin
        if (root == nullptr) return 0;
        int l = giveCoin(root->left);
        int r = giveCoin(root->right);
        moves += abs(l) + abs(r);
        return root->val - 1 + l + r;
    }
    int distributeCoins(TreeNode* root) {
        moves = 0;
        giveCoin(root);
        return moves;
    }
};
