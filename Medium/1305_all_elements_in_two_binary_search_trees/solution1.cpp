/**
 * Title:  All Elements in Two Binary Search Trees (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, Jan, 2022
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
    vector<int> vec1;
    vector<int> vec2;
public:
    void run(TreeNode* root, int id) {
        if (root == nullptr)
            return;
        run(root->left, id);
        if (id == 1)
            vec1.emplace_back(root->val);
        else
            vec2.emplace_back(root->val);
        run(root->right, id);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        run(root1, 1);
        run(root2, 2);
        int n = (int)vec1.size();
        int m = (int)vec2.size();
        
        if (n == 0) {
            return vec2;
        } else if (m == 0) {
            return vec1;
        }
        
        vector<int> ans;
        int i = 0;
        int j = 0;
        
        while (i < n && j < m) {
            if (vec1[i] < vec2[j]) {
                ans.emplace_back(vec1[i]);
                i++;
            } else {
                ans.emplace_back(vec2[j]);
                j++;
            }
        }
        if (i == n && j < m) {
            while (j < m) {
                ans.emplace_back(vec2[j]);
                j++;
            }
        } else if (j == m && i < n) {
            while (i < n) {
                ans.emplace_back(vec1[i]);
                i++;
            }
        }
        return ans;
    }
};
