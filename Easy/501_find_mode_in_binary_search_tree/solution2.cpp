/**
 * Title:  Find Mode in Binary Search Tree (Leetcode Easy 501)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, November, 2023
 * Method: Inorder traverse will keep meeting the same number until it never appears.
 * Result: Time Complexity O(n), Space Complexity O(n)
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
    vector<int> ans;
    int last_num;
    int count;
    int max_count;
public:
    void navigate(TreeNode* root) {
        // Use inorder traverse so we will keep meeting the same number
        if (root == nullptr)
            return;
        navigate(root->left);
        if (root->val == last_num) {
            count++;
        } else {
            count = 1;
        }

        if (count > max_count) {
            ans.clear();
            ans.emplace_back(root->val);
            max_count = count;
        } else if (count == max_count){
            ans.emplace_back(root->val);
        }

        last_num = root->val;
        navigate(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        last_num = -1000000;
        count = 0;
        max_count = 0;
        navigate(root);
        return ans;
    }
};
