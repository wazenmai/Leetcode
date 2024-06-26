/**
 * Title:  Remove Nodes From Linked List (Leetcode Medium 2487)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, May, 2024
 * Method: Use recursion instead of loop, remove node without deleting it.
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
    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr) return head;
        head->next = removeNodes(head->next);
        if (head->next == nullptr) return head;
        if (head->next->val > head->val) return head->next;
        return head;
    }
};
