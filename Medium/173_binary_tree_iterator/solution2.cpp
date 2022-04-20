/**
 * Title:  Binary Tree Iterator (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, April, 2022
 * Method: O(1) time to find next, O(h) memory
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
    stack<TreeNode*> st;
    TreeNode* root;
    
    int getNext() {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        int e = root->val;
        root = root->right;
        return e;
    }
public:
    BSTIterator(TreeNode* root) {
        this->root = root;
    }
    
    int next() {
        return getNext();
    }
    
    bool hasNext() {
        return root != nullptr || st.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
