/**
 * Title:  Merge Two Sorted Lists (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   7, Mar, 2022
 * Method: Tidy the code
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
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
                cur = cur->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
                cur = cur->next;
            }
        }
        
        cur->next = list1 ? list1 : list2;
        
        return head->next;
    }
};
