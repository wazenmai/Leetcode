/**
 * Title:  Reverse Linked List II (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, September, 2023
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;
        ListNode* start = head;
        ListNode* end = nullptr;
        ListNode* l;
        ListNode* r;
        ListNode* cur = head;
        for (int i = 1; i <= right; i++) {
            if (i == left)
                l = cur;
            if (i + 1 == left)
                start = cur;
            if (i == right) {
                r = cur;
                end = cur->next;
            }
            cur = cur->next;
        }
        ListNode* prev;
        cur = l;
        prev = end;
        while (cur != r) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        cur->next = prev;
        if (l == head) {
            head = r;
        } else {
            start->next = r;
        }
        return head;
    }
};
