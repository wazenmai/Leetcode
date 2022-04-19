/**
 * Title:  Recover Binary Search Tree (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, April, 2022
 * Method: O(n) space record the inorder tree, then O(n) time search for the swap nodes.
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
    vector<TreeNode*> v;
public:
    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;
        inorder(root->left);
        v.emplace_back(root);
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        int n = (int)v.size();
        int first = -1, second = -1, third = -1;
        for (int i = 0; i < n - 1; i++) {
            if (v[i]->val > v[i + 1]->val) { // sth wrong
                if (first == -1) {
                    first = i;
                    second = i + 1;
                } else {
                    third = i + 1;
                }
            }
        }
        if (third == -1) {
            int temp = v[first]->val;
            v[first]->val = v[second]->val;
            v[second]->val = temp;
        } else {
            int temp = v[first]->val;
            v[first]->val = v[third]->val;
            v[third]->val = temp;
        }
    }
};
