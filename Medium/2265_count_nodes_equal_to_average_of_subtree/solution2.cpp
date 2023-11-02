/**
 * Title:  Count Nodes Equal to Average of Subtree (Leetcode Medium 2265)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, November, 2023
 * Method: DFS. Delete the branch condition by return (0, 0) when the node is nullptr.
 * Result: Time Complexity O(n), Space Complexity O(n) -> 0ms
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
    pair<int, int> check(TreeNode* root) {
        if (root == nullptr)
            return make_pair(0, 0);
        auto l = check(root->left);
        auto r = check(root->right);
        if (round((l.first + r.first + root->val) / (l.second + r.second + 1)) == root->val)
            ans++;
        return make_pair(l.first + r.first + root->val, r.second + l.second + 1);
    }
    int averageOfSubtree(TreeNode* root) {
       ans = 0;
       auto temp = check(root);
       return ans;  
    }
};
