/**
 * Title:  Find Mode in Binary Search Tree (Leetcode Easy 501)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, November, 2023
 * Method: Use map to record the occurence.
 * Result: Time Complexity O(nlogn), Space Complexity O(n)
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
    unordered_map<int, int> m;
    int occur;
public:
    void navigate(TreeNode* root) {
        if (root == nullptr)
            return;
        if (m.find(root->val) == m.end()) {
            m[root->val] = 1;
            occur = max(1, occur);
        } else {
            m[root->val]++;
            occur = max(m[root->val], occur);
        }
        navigate(root->left);
        navigate(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        occur = 0;
        navigate(root);
        vector<int> ans;
        for (auto const& x: m) {
            if (x.second == occur)
                ans.emplace_back(x.first);
        }
        return ans;
    }
};
