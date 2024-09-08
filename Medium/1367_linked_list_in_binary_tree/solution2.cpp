/**
 * Title:  Linked List in Binary Tree (Leetcode Medium 1367)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, September, 2024
 * Method: Iterative. The first stack save start node from tree. The second stack in `isMatch` save the current node from linked list and tree.
 * Result: Time complexity O(n * m), space complexity O(n). n = # of nodes in tree and m = # of nodes in linked list.
 */

class Solution {
public:
    bool isMatch(ListNode* head, TreeNode* root) {
        stack<pair<ListNode*, TreeNode*>> s;
        s.push({head, root});
        while (!s.empty()) {
            auto [lst, tree] = s.top();
            s.pop();
            while (lst != nullptr && tree != nullptr) {
                if (lst->val != tree->val) break;
                lst = lst->next;
                if (lst) {
                    if (tree->left) s.push({lst, tree->left});
                    if (tree->right) s.push({lst, tree->right});
                    break;
                }
            }
            if (lst == nullptr) return true;
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) return false;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            auto node = st.top();
            st.pop();
            if (isMatch(head, node)) return true;
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        return false;
    }
};
