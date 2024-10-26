/**
 * Title:  Height of Binary Tree After Subtree Removal Queries (Leetcode Hard 2458)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, October, 2024
 * Method: 1. Preprocess the tree to get every node's parent, depth (left = 0), distance from root (root = 0), and the list of nodes that are in the same distance from root. Also mark the node in the longest path.
 *         2. Process the query. Four cases: (1) previous query - return stored answer directly (2) not on the longest path - return tree height directly (3) exist other node at the same level, (4) q is a critical node.
 *         For case (3), we can iterate other same-level nodes to get the maximum height of the subtree. For case (4), the height can only start from its parent level, which is tree_height - height[q] - 1.
 * Result: Time complexity is O(n + m * alpha). alpha is the time for case (3). Space complexity is O(n).
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
    unordered_map<int, vector<int>> dist_from_root_to_node; // dist from root: (node_val of that depth)
    unordered_map<int, int> dist_from_root; // node_val: dist from root
    unordered_map<int, int> height; // node_val: path of height, leaf = 0
    unordered_map<int, int> parent;
    unordered_set<int> longest; // node in longest path
public:
    int traverse(TreeNode* root, int level) {
        if (root == nullptr) return -1;
        if (root->left) parent[root->left->val] = root->val;
        if (root->right) parent[root->right->val] = root->val;
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
        // Step 1. Preprocess
        // 1.1 Get every node's parent
        // 1.2 Get every node's depth (leaf = 0)
        // 1.3 Get every node's distance from root (root = 0)
        // 1.4 Get the list of nodes that are in same dist from root
        int tree_height = traverse(root, 0);
        int m = queries.size();
        find_longest(root);
        // cout << "tree_height = " << tree_height << "\n";
        // cout << "---dist from root to node---\n";
        // for (auto it = dist_from_root_to_node.begin(); it != dist_from_root_to_node.end(); it++) {
        //     cout << it->first << ": ";
        //     for (auto& e: it->second) {
        //         cout << e << ",";
        //     }
        //     cout << "\n";
        // }
        
        // Step 2. Process query
        unordered_map<int, int> query; // save existed query
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int q = queries[i];
            // cout << "(" << i << "," << q << "): ";
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