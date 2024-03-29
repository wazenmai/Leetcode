/**
 * Title:  All Possible Full Binary Trees (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, July, 2023
 * Method: DP[i]: the binary tree nodes that contains i nodes. Time complexity: O(2^n/2), Space complexity: O(n * 2^n/2)
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
    vector<vector<TreeNode*>> dp;
public:
    vector<TreeNode*> solve(int n) {
        if (n % 2 == 0)
            return {};
        if (dp[n].size() != 0)
            return dp[n];
        if (n == 1) {
            TreeNode* new_node = new TreeNode(0);
            return {new_node};
        }
        vector<TreeNode*> res;
        for (int i = 1; i < n; i+= 2) {
            vector<TreeNode*> left = solve(i);
            vector<TreeNode*> right = solve(n - i - 1);
            for (TreeNode* l: left) {
                for (TreeNode* r: right) {
                    TreeNode* root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    res.emplace_back(root);
                }
            }
        }
        return dp[n] = res;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        dp.resize(n + 1);
        return solve(n);
    }
};

/*
dp[i]: the binary tree nodes that contains i nodes 
*/
