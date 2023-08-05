/**
 * Title:  Unique Binary Search Trees II (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, August, 2023
 * Method: Iterative DP - Space optimization. dp[i] = BSTs with n nodes that value range from 1 to n.
 */

class Solution {
public:
    void levelTraversal(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        cout << "[";
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur == nullptr) {
                cout << "null, ";
                continue;
            }
            cout << cur->val << ", ";
            if (cur->left == nullptr && cur->right == nullptr)
                continue;
            q.push(cur->left);
            q.push(cur->right);
        }
        cout << "]\n";
    }

    TreeNode* addTree(TreeNode* node, int offset) {
        if (node == nullptr)
            return nullptr;
        TreeNode* cur = new TreeNode(node->val + offset);
        cur->left = addTree(node->left, offset);
        cur->right = addTree(node->right, offset);
        return cur;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> dp(n+1);
        dp[0].emplace_back(nullptr);
        dp[1].emplace_back(new TreeNode(1));
        for (int nodes = 2; nodes <= n; nodes++) {
            for (int i = 1; i <= nodes; i++) {
                for (auto left: dp[i - 1]) {
                    for (auto right: dp[nodes - i]) {
                        TreeNode* root = new TreeNode(i, left, addTree(right, i));
                        dp[nodes].emplace_back(root);
                    }
                }
            }
            // cout << nodes << " nodes\n";
            // for (auto tree: dp[nodes]) {
            //     levelTraversal(tree);
            // }
        }
        return dp[n];
    }
};
