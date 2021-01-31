/**
 * Title:  Add Two Numbers (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, Jan, 2021
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = l1;
        int8_t carry = 0;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val + l2->val + carry >= 10) {
                l1->val = l1->val + l2->val + carry - 10;
                carry = 1;
            } else {
                l1->val = l1->val + l2->val + carry;
                carry = 0;
            }
            
            if (l1->next == nullptr && l2->next != nullptr) {
                l1->next = l2->next;
                l2->next = nullptr;
                l1 = l1->next;
                l2->val = 0;
            } else if (l2->next == nullptr && l1->next != nullptr) {
                l2->val = 0;
                l1 = l1->next;
            } else if (l1->next == nullptr && l2->next == nullptr) {
                break;
            } else {
                l1 = l1->next;
                l2 = l2->next;
            }
        }
        if (carry == 1) {
            l1->next = new ListNode(1);
        }
        return ans;
    }
};