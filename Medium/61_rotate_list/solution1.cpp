/**
 * Title:  Rotate List (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, Mar, 2022
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;
        int n = 1;
        ListNode *cur = head;
        while (cur->next != nullptr) {
            n++;
            cur = cur->next;
        }
        // cout << n << "\n";
        k = n - (k % n);
        if (k == n)
            return head;
        // cout << k << "\n";
        ListNode *last = cur;
        ListNode *pre = head;
        cur = head;
        for (int i = 0; i < k; i++) {
            pre = cur;
            cur = cur->next;
        }
        if (cur->next == nullptr) {
            cur->next = head;
        } else {
            last->next = head;
        }
        pre->next = nullptr;
        head = cur;
        return head;
    }
};
