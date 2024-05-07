/**
 * Title:  Double a Number Represented as a Linked List (Leetcode Medium 2816)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, May, 2024
 * Method: Use recursion and global carry to double the number represented as a linked list.
 * Result: Time complexity is O(n), space complexity is O(1).
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
    int carry = 0;
    ListNode* helper(ListNode* head) {
        if (head == nullptr) return head;
        head->next = helper(head->next);
        int num = head->val * 2 + carry;
        carry = num / 10;
        head->val = num % 10;
        return head;
    }

    ListNode* doubleIt(ListNode* head) {
        head = helper(head);
        if (carry > 0) {
            ListNode* node = new ListNode(carry);
            node->next = head;
            head = node;
        }
        return head;
    }
};