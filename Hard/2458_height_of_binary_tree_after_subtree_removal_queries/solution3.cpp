/**
 * Title:  Height of Binary Tree After Subtree Removal Queries (Leetcode Hard 2458)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, October, 2024
 * Method: Calculate the maximum height of the tree after removing specific node at first. Then asnwer the query in O(1).
 *         1. Traverse the tree from left to right, update max_height_after_removal by the current maximum height before meeting this node, then update the maximum height.
 *         2. Traverse the tree from right to left, update max_height_after_removal by the maximum height before meeting this node compared to original stored value obtained last round, then update the maximum height.
 *         In this way, we can make sure all the max_height_after_removal is correct, because we have already met all the possibilities.
 * Result: Time complexity O(n+m), Space complexity O(n). Runtime 2572ms -> 8ms. Memory: 481.9MB -> 183.9MB.
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
    int max_height_after_removal[100001];
    int max_height = 0;
public:
    void travel_left_to_right(TreeNode* root, int cur_height) {
        if (root == nullptr) return;
        // max_height: the maximum height we met so far before meeting this root
        max_height_after_removal[root->val] = max_height;
        // update max_height after we meet this root
        max_height = max(max_height, cur_height);
        // update from left to right
        travel_left_to_right(root->left, cur_height + 1);
        travel_left_to_right(root->right, cur_height + 1);
    }
    void travel_right_to_left(TreeNode* root, int cur_height) {
        if (root == nullptr) return;
        max_height_after_removal[root->val] = max(max_height_after_removal[root->val], max_height);
        max_height = max(max_height, cur_height);
        // update from right to left
        travel_right_to_left(root->right, cur_height + 1);
        travel_right_to_left(root->left, cur_height + 1);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // Strategy: First compute all the possible answer, and O(1) process query.
        travel_left_to_right(root, 0);
        max_height = 0;
        travel_right_to_left(root, 0);
        
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            ans[i] = max_height_after_removal[queries[i]];
        }
        return ans;
    }
};
