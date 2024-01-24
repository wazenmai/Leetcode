/**
 * Title:  Pseudo-Palindromic Paths in a Binary Tree (Leetcode Medium 1457)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, Janurary, 2024
 * Method: DFS. record # of occurence of each number in the path, and check if the path is pseudo-palindromic.
 * Result: Time complexity O(N). Space complexity O(N)
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
    int ans;
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        ans = 0;
        vector<int> v(10, 0);
        dfs(root, v);
        return ans;
    }
    void dfs(TreeNode* root, vector<int>& v) {
        if (root == nullptr) return;
        // cout << "dfs " << root->val << "\n";
        v[root->val]++;
        if (root->left == nullptr && root->right == nullptr) check(v);
        dfs(root->left, v);
        dfs(root->right, v);
        v[root->val]--;
    }
    void check(vector<int>& v) {
        int odd = 0;
        for (int i = 0; i < 10; i++) {
            if (v[i] & 1) odd++;
        }
        if (odd <= 1) ans++;
        // cout << ", ans: " << ans << "\n";
    }
};
