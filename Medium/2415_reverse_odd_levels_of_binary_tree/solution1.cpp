/**
 * Title:  Reverse Odd Levels of Binary Tree (Leetcode Medium 2415)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, December, 2024
 * Method: First traverse the tree and store the values of each node in an array. Then reverse the values of each odd level in the array. Finally, traverse the tree again and assign the values in the array to the nodes.
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
private:
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<int> v(17000, 0);
        int n = 0;
        
        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int i) {
            if (node == nullptr) return;
            n = max(n, i);
            v[i] = node->val;
            dfs(node->left, i * 2 + 1);
            dfs(node->right, i * 2 + 2);
        };

        function<void(TreeNode*, int)> rev = [&](TreeNode* node, int i) {
            if (node == nullptr) return;
            node->val = v[i];
            rev(node->left, i * 2 + 1);
            rev(node->right, i * 2 + 2);
        };
        
        dfs(root, 0);
        int index = 1;
        int node = 2;
        for (int i = 0; i <= n; i++) {
            if (i == index) {
                for (int j = 0; j < node / 2; j++) {
                    int temp = v[i + j];
                    v[i + j] = v[i + node - 1 - j];
                    v[i + node - 1 - j] = temp;
                }
                index = 4 * index + 3;
                node *= 4;
            }
        }
        rev(root, 0);
        return root;
    }
};

// 1: 2
// 3: 4
// 7: 8
// 15: 16
