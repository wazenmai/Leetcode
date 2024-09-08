/**
 * Title:  Linked List in Binary Tree (Leetcode Medium 1367)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, September, 2024
 * Method: DFS to check whether root is the start of the linked list, and recursively check the left and right child of the root.
 * Result: Time complexity O(n * m), space complexity O(n+m). n = # of nodes in tree and m = # of nodes in linked list.
 */

class Solution {
public:
    bool dfs(ListNode* head, TreeNode* root) {
        if (head == nullptr) return true;
        if (root == nullptr) return false;
        if (head->val != root->val) return false;
        if (dfs(head->next, root->left)) return true;
        return dfs(head->next, root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) return false;
        if (dfs(head, root)) return true;
        if (isSubPath(head, root->left)) return true;
        return isSubPath(head, root->right);
    }
};
