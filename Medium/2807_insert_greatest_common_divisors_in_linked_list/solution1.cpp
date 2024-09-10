/**
 * Title:  Insert Greatest Common Divisors in Linked List (Leetcode Medium 2807)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, September, 2024
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
    int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* nxt = cur->next;
            if (cur && nxt) {
                // insert gcd
                ListNode* val = new ListNode(gcd(cur->val, nxt->val));
                cur->next = val;
                val->next = nxt;
            }
            cur = nxt;
        }
        return head;
    }
};
