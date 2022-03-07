/**
 * Title:  Merge Two Sorted Lists (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   7, Mar, 2022
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        ListNode* head = new ListNode(-200);
        ListNode* cur = head;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        
        while (cur1 && cur2) {
            if (cur1->val < cur2->val) {
                cur->next = cur1;
                cur1 = cur1->next;
                cur = cur->next;
            } else {
                cur->next = cur2;
                cur2 = cur2->next;
                cur = cur->next;
            }
        }
        
        if (!cur1) {
            cur->next = cur2;
            cur2 = cur2->next;
            cur = cur->next;
        } else if (!cur2) {
            cur->next = cur1;
            cur1 = cur1->next;
            cur = cur->next;
        }
        
        return head->next;
    }
};
