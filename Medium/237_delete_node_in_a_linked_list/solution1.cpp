/**
 * Title:  Delete Node in a Linked List (Leetcode Medium 237)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, May, 2024
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* cur = node;
        ListNode* nxt = cur->next;
        ListNode* prev = cur;
        while (nxt != nullptr) {
            cur->val = nxt->val;
            prev = cur;
            cur = cur->next;
            nxt = nxt->next;
        }
        prev->next = nullptr;
        delete cur;
    }
};
