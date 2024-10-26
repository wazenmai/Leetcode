/**
 * Title:  Height of Binary Tree After Subtree Removal Queries (Leetcode Hard 2458)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, October, 2024
 * Method: Delete unused `parent` from solution1.cpp.
 * Result: Runtime 2572ms -> 2184ms. Memory: 481.9MB -> 391.8MB
 */

class Solution {
private:
    unordered_map<int, vector<int>> dist_from_root_to_node; // dist from root: (node_val of that depth)
    unordered_map<int, int> dist_from_root; // node_val: dist from root
    unordered_map<int, int> height; // node_val: path of height, leaf = 0
    unordered_set<int> longest; // node in longest path
public:
    int traverse(TreeNode* root, int level) {
        if (root == nullptr) return -1;
        dist_from_root[root->val] = level;
        dist_from_root_to_node[level].emplace_back(root->val);
        return height[root->val] = max(traverse(root->left, level + 1), traverse(root->right, level + 1)) + 1;
    }
    void find_longest(TreeNode* root) {
        if (root == nullptr) return;
        longest.insert(root->val);
        if (root->left && root->right) {
            if (height[root->left->val] == height[root->right->val]) return;
            if (height[root->left->val] + 1 == height[root->val]) {
                find_longest(root->left);
            } else {
                find_longest(root->right);
            }
        } else {
            find_longest(root->left);
            find_longest(root->right);
        }
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int tree_height = traverse(root, 0);
        int m = queries.size();
        find_longest(root);
        unordered_map<int, int> query; // save existed query
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int q = queries[i];
            if (query.find(q) != query.end()) { // previuos query
                ans[i] = query[q];
            } else if (longest.find(q) == longest.end()) { // not on longest path
                ans[i] = tree_height;
            } else {
                int d = dist_from_root[q];
                if (dist_from_root_to_node[d].size() > 1) { // exist other node at same level (dist from root)
                    int new_h = 0;
                    for (auto& e: dist_from_root_to_node[d]) {
                        if (e == q) continue;
                        new_h = max(new_h, height[e]);
                    }
                    ans[i] = tree_height - height[q] + new_h;
                } else { // q is a critical node
                    ans[i] = tree_height - height[q] - 1;
                }
            }
            query[q] = ans[i];
        }
        return ans;
    }
};
