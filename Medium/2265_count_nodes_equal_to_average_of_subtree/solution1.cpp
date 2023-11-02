/**
 * Title:  Count Nodes Equal to Average of Subtree (Leetcode Medium 2265)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, November, 2023
 * Method: DFS. Use pair to store the sum and the number of nodes in the subtree.
 * Result: Time Complexity O(n), Space Complexity O(n) -> 9ms
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
            return make_pair(-1, -1);
        auto l = check(root->left);
        auto r = check(root->right);
        // cout << "check " << root->val << ": " << ans << "\n";
        if (l.first == -1 && r.first == -1) { // leaf
            ans++;
            return make_pair(root->val, 1);
        } else if (l.first == -1) {
            if (round((r.first + root->val) / (r.second + 1)) == root->val)
                ans++;
            // cout << r.first << " " << r.second << "\n";
            // cout << round((r.first + root->val) / (r.second + 1)) << "\n";
            return make_pair(r.first + root->val, r.second + 1);
        } else if (r.first == -1) {
            if (round((l.first + root->val) / (l.second + 1)) == root->val)
                ans++;
            // cout << round((l.first + root->val) / (l.second + 1)) << "\n";
            return make_pair(l.first + root->val, l.second + 1);
        } else {
            if (round((l.first + r.first + root->val) / (l.second + r.second + 1)) == root->val)
                ans++;
            // cout << round((l.first + r.first + root->val) / (l.second + r.second + 1)) << "\n";
            return make_pair(l.first + r.first + root->val, r.second + l.second + 1);
        }
    }
    int averageOfSubtree(TreeNode* root) {
       ans = 0;
       auto temp = check(root);
       return ans;  
    }
};
