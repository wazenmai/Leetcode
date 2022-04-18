/**
 * Title:  Kth Smallest Element in BST (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, April, 2022
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
    int cur = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr)
            return 0;
        int ans = kthSmallest(root->left, k);
        if (ans)
            return ans;
        ++cur;
        if (k == cur)
            return root->val;
        return kthSmallest(root->right, k);
    }
};
