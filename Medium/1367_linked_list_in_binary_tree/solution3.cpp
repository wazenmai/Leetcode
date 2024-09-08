/**
 * Title:  Linked List in Binary Tree (Leetcode Medium 1367)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, September, 2024
 * Method: Use KMP algorithm to deal with repeated pattern in linked list. First make the pattern and prefix table from linked list, then search the pattern in tree. If it is not match, we can use the prefix table to skip some nodes.
 * Result: Time complexity O(n + m), space complexity O(n + m). n = # of nodes in tree and m = # of nodes in linked list.
 */
class Solution {
public:
    bool search(TreeNode* root, int id, const vector<int>& pattern, const vector<int>& prefix) {
        if (root == nullptr) return false;
        while (id && root->val != pattern[id]) {
            id = prefix[id - 1];
        }
        id += root->val == pattern[id];
        if (id == pattern.size()) return true;
        if (search(root->left, id, pattern, prefix)) return true;
        return search(root->right, id, pattern, prefix);
    }
    void print(const vector<int>& v) {
        for (auto& num: v) {
            cout << num << " ";
        }
        cout << "\n";
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<int> pattern = {head->val};
        vector<int> prefix = {0};
        int lps = 0;
        head = head->next;
        while (head) {
            while (lps && head->val != pattern[lps]) {
                lps = prefix[lps - 1];
            }
            lps += head->val == pattern[lps];
            pattern.emplace_back(head->val);
            prefix.emplace_back(lps);
            head = head->next;
        }
        // print(prefix);
        return search(root, 0, pattern, prefix);
    }
};
