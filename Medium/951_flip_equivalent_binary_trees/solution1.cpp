/**
 * Title:  Flip Equivalent Binary Trees (Leetcode Medium 951)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, October, 2024
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return true;
        if (root1 == nullptr || root2 == nullptr) return false;
        if (root1->val != root2->val) return false;
        // cout << "compare " << root1->val << ", " << root2->val << "\n";
        if (root1->left && root1->right) { // both have value
            if (!(root2->left && root2->right)) return false;
            if ((root1->left->val == root2->left->val) && (root1->right->val == root2->right->val)) { // same
                return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
            } else if ((root1->left->val == root2->right->val) && (root1->right->val == root2->left->val)) { // flip same
                return flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
            } else {
                return false;
            }
        } else if (root1->left) {
            if (root2->left && root2->left->val == root1->left->val && !(root2->right)) {
                return flipEquiv(root1->left, root2->left);
            } else if (root2->right && root2->right->val == root1->left->val && !(root2->left)) {
                return flipEquiv(root1->left, root2->right);
            } else {
                return false;
            }
        } else if (root1->right) {
            if (root2->left && root2->left->val == root1->right->val && !(root2->right)) {
                return flipEquiv(root1->right, root2->left);
            } else if (root2->right && root2->right->val == root1->right->val && !(root2->left)) {
                return flipEquiv(root1->right, root2->right);
            } else {
                return false;
            }
        } else if (!(root2->left) && !(root2->right)) {
            return true;
        }
        return false;
    }
};
