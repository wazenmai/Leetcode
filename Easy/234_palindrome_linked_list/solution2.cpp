/**
 * Title:  Palindrome Linked List (Leetcode Easy 234)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, March, 2024
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode* cur = head;
        vector<int> v;
        while (cur != nullptr) {
            n++;
            v.emplace_back(cur->val);
            cur = cur->next;
        }
        cur = head;
        for (int i = 0; i < n / 2; i++) {
            if (cur->val != v[n - 1 - i]) return false;
            cur = cur->next;
        }
        return true;
    }
};

// 0 1 0, 3 1
// 0 1 1 0, 4, 2

