/**
 * Title:  Unique Binary Search Trees II (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, August, 2023
 * Method: Recursive DP
 */

class Solution {
public:
    vector<TreeNode*> generateTree(int start, int end, map<pair<int, int>, vector<TreeNode*>>& dp) {
        vector<TreeNode*> res;
        if (start > end) {
            res.emplace_back(nullptr);
            return res;
        }
        if (dp.find(make_pair(start, end)) != dp.end()) {
            return dp[make_pair(start, end)];
        }
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftSubTrees = generateTree(start, i - 1, dp);
            vector<TreeNode*> rightSubTrees = generateTree(i + 1, end, dp);
            for (auto left: leftSubTrees) {
                for (auto right: rightSubTrees) {
                    TreeNode* root = new TreeNode(i, left, right);
                    res.emplace_back(root);
                }
            }
        }
        return dp[make_pair(start, end)] = res;
    }
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> dp; // (start, end): Tree
        return generateTree(1, n, dp);
    }
};
