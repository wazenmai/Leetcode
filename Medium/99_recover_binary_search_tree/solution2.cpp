/**
 * Title:  Recover Binary Search Tree (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, April, 2022
 * Method: O(1) space, then O(n) time search for the swap nodes. prev is the previous travel node.
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
    TreeNode *first, *second, *prev;
public:
    void travel(TreeNode* root) {
        if (root == nullptr)
            return;
        travel(root->left);
        if (prev) {
            if (prev->val > root->val) {
                if (first == nullptr)
                    first = prev;
                second = root;
            }
        }
        prev = root;
        travel(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        first = second = prev = nullptr;
        travel(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};
