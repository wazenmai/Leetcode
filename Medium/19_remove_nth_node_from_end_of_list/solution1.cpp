/**
 * Title:  Remove Nth Node From End of List (Leetcode Medium 19)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, March, 2024
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        int total = 0;
        while (cur != nullptr) {
            cur = cur->next;
            total++;
        }
        int target = total - n;
        // cout << "total: " << total << ", target: " << target << "\n";
        cur = head;
        ListNode* prev = head;
        for (int i = 0; i < target; i++) {
            prev = cur;
            cur = cur->next;
        }
        // cout << "now we are on " << cur->val << ", prev = " << prev->val << "\n";
        if (cur != head) {
            prev->next = cur->next;
            delete cur;
        } else {
            head = head->next;
            delete cur;
        }
        return head;
    }
};
