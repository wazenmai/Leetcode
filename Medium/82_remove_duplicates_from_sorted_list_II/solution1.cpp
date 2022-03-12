/**
 * Title:  Remove Duplicates from Sorted List II (Leetcode Medium)
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *cur = head;
        ListNode *pre = head;
        bool remove = false;
        while (cur->next) {
            if (cur->val == cur->next->val) {
                remove = true;
                if (cur == head) {
                    head = head->next;
                } else {
                    pre->next = cur->next;
                    cur = pre;
                }
            } else if (remove) {
                remove = false;
                if (cur == head) {
                    head = head->next;
                } else {
                    pre->next = cur->next;
                    cur = pre;
                }
            }
            pre = cur;
            cur = cur->next;
        }
        if (remove) {
            if (cur == head)
                head = head->next;
            else 
                pre->next = cur->next;
        }
        return head;
    }
};
