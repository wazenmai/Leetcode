/**
 * Title:  Amount of Time for Binary Tree to Be Infected (Leetcode Medium 2385)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, Janurary, 2024
 * Method: To know the distance of root to farest child, we need three value: root->parent, root->parent->another side farest child, root->child.
    *      So I use pair, first is the node pointer of start node, second is vector<int> include the distance of above three values. The final answer will be the max of them.
    *      Helper funciton: int findLevel(TreeNode* root, int level): find the height of the tree from root
 * Result: Time complexity: O(n), Space complexity: O(n)
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
    pair<TreeNode*, vector<int>> findStart(TreeNode* root, int start, int level) {
        if (root == nullptr) {
            return make_pair(root, vector<int>{level - 1, level - 1, 0});
        }
        if (root->val == start) {
            // find down
            int step = max(findLevel(root->left, level + 1), findLevel(root->right, level + 1));
            // cout << "find start(" << start << "), the child path: " << step << "\n";
            return make_pair(root, vector<int>{level, level, step - level});
        }
        auto left = findStart(root->left, start, level + 1);
        auto right = findStart(root->right, start, level + 1);
        if (left.first == right.first) {
            if (left.second[0] >= right.second[0]) return left;
            return right;
        } else if (left.first != nullptr) {
            // cout << "Parent level " << level << ", start level " << left.second[0] << ", another side height: " << right.second[0] << ", start to another side: " << left.second[0] - level + right.second[0] - level << "\n";
            return make_pair(left.first, vector<int>{left.second[0], max(right.second[0] - level + left.second[0] - level, left.second[1]), left.second[2]});
        }
        return make_pair(right.first, vector<int>{right.second[0], max(right.second[0] - level + left.second[0] - level, right.second[1]), right.second[2]});
    }
    int findLevel(TreeNode* root, int level) {
        if (root == nullptr) return level - 1;
        return max(findLevel(root->left, level + 1), 
                   findLevel(root->right, level + 1));
    }
    int amountOfTime(TreeNode* root, int start) {
        if (root->val == start) return findLevel(root, 0);
        
        int leftHeight = findLevel(root->left, 1);
        int rightHeight = findLevel(root->right, 1);
        // cout << "leftHeight: " << leftHeight << ", rightHeight: " << rightHeight << "\n";

        auto l = findStart(root->left, start, 1);
        // cout << "left: " << l.second[0] << ", " << l.second[1] << ", " << l.second[2] << "\n";
        if (l.first != nullptr) {
            int right = findLevel(root->right, 1);
            // cout << "right: " << right << "\n";
            return max(max(right + l.second[0], l.second[1]), l.second[2]);
        }
        // cout << "left farest distance: " << l.second[0] << "\n";
        auto r = findStart(root->right, start, 1);
        // cout << "right: " << r.second[0] << ", " << r.second[1] << ", " << r.second[2] << "\n";
        return max(max(l.second[0] + r.second[0], r.second[1]), r.second[2]);
    }
};
// the node pointer (nullptr if not the start)
// the distance to root->left (up), 
// the distance to farest child (up and another side)
// the distance to its child (down)
