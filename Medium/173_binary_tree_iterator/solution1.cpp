/**
 * Title:  Binary Tree Iterator (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, April, 2022
 * Method: O(1) time to find next, O(n) memory
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
class BSTIterator {
private:
    vector<int> v;
    int pt;
    int n;
    
    void inorder(TreeNode* root) {
        if (root == nullptr)
            return;
        inorder(root->left);
        v.emplace_back(root->val);
        inorder(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        pt = -1;
        inorder(root);
        n = (int)v.size();
    }
    
    int next() {
        pt++;
        return v[pt];
    }
    
    bool hasNext() {
        if (pt < n - 1)
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
