/**
 * Title:  Even Odd Tree (Leetcode Medium 1609)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, February, 2024
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
    vector<int> v;
    bool checkLevel(TreeNode* root, int level) {
        if (root == nullptr) return true;
        if ((level & 1) && (root->val & 1)) return false;
        if (!(level & 1) && !(root->val & 1)) return false;
        if (v.size() == level) { // first value in this level
            v.emplace_back(root->val);
        } else {
            // odd level: even decrease
            if ((level & 1) && root->val >= v[level]) return false;
            // even level: odd increase
            if ((!(level & 1)) && root->val <= v[level]) return false;
            v[level] = root->val;
        }
        
        bool l = (root->left) ? checkLevel(root->left, level + 1) : true;
        bool r = (root->right) ? checkLevel(root->right, level + 1) : true;
        return l && r;
    }
    bool isEvenOddTree(TreeNode* root) {
        return checkLevel(root, 0);
    }
};
