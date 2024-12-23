/**
 * Title:  Minimum Number of Operations to Sort a Binary Tree by Level (Leetcode Medium 2471)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, December, 2024
 * Method: BFS level traversal. Get min swaps by first sort the current level get the answer, then use hash map to record the position of the numbers. Iterate through the cur_level, if cur[i] != target[i], we swap the value of index i and index of number target[i] (stored in hash map).
 * Result: Time complexity O(nlogn). Space complexity O(n). n is the number of nodes in the binary tree.
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
    int get_min_swaps(vector<int>& cur_level) {
        int swaps = 0;
        int n = cur_level.size();
        vector<int> target = cur_level;
        sort(target.begin(), target.end()); // target level
        unordered_map<int, int> pos;
        // Track current position of values
        for (int i = 0; i < n; i++) {
            pos[cur_level[i]] = i;
        }
        // For each position, swap until correct value is placed
        for (int i = 0; i < n; i++) {
            if (cur_level[i] != target[i]) {
                swaps++;
                int cur_pos = pos[target[i]];
                pos[cur_level[i]] = cur_pos;
                swap(cur_level[cur_pos], cur_level[i]);
            }
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            vector<int> cur_level;
            while (s--) {
                auto cur = q.front();
                q.pop();
                cur_level.emplace_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            ans += get_min_swaps(cur_level);
        }
        return ans;
    }
};
