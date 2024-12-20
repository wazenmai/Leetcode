/**
 * Title:  Reverse Odd Levels of Binary Tree (Leetcode Medium 2415)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, December, 2024
 * Method: Use level traversal to traverse the tree. If the level is odd, store the nodes in a vector. After traversing the tree, reverse the values of the nodes in the vector. Finally, traverse the tree again and assign the values in the vector to the nodes.
 * Result: Time complexity O(n), Space complexity O(n).
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        // level traversal
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> v;
        int level = 0;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                auto cur = q.front();
                q.pop();
                if (cur->left) {
                    q.push(cur->left);
                    q.push(cur->right);
                }
                if (level & 1) {
                    v.emplace_back(cur);
                }
            }
            if (level & 1) {
                int nodes = v.size();
                for (int i = 0; i < nodes / 2; i++) {
                    swap(v[i]->val, v[nodes - 1 - i]->val);
                }
                v.clear();
            }
            level++;
        }
        return root;
    }
};
