/**
 * Title:  Reverse Linked List (Leetcode Easy 206)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, March, 2024
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* cur = head->next;
        ListNode* prev = head;
        ListNode* h = head;
        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        head = prev;
        h->next = nullptr;
        return head;
    }
};
