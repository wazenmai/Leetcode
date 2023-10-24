/**
 * Title:  Find Largest Value in Each Tree Row (Leetcode Medium 515)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, October, 2023
 * Method: Add a new element to the vector if the height of the tree is larger than the size of the vector, otherwise, update the element in the vector
 * Result: Time Complexity O(n), Space Complexity O(n)
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
    int treeHeight(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left_height = treeHeight(root->left);
        int right_height = treeHeight(root->right);
        return max(left_height, right_height) + 1;
    }

    void findLarge(TreeNode* root, vector<int>& ans, int height) {
        if (root == nullptr)
            return;
        if (ans.size() < height + 1) {
            ans.emplace_back(root->val);
        } else {
            ans[height] = max(ans[height], root->val);
        }
        findLarge(root->left, ans, height + 1);
        findLarge(root->right, ans, height + 1);
    }

    vector<int> largestValues(TreeNode* root) {
        // find the height of the tree
        // int rows = treeHeight(root);
        // cout << rows << "\n";
        vector<int> ans;
        findLarge(root, ans, 0);
        return ans;
    }
};
