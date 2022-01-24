/**
 * Title:  Insertion Sort List (Leetcode Medium 147)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, Dec, 2021
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *cur = head->next;
        ListNode *anshead = new ListNode(head->val);
        ListNode *ansend = anshead;
        
        while (cur != nullptr) {
            ListNode *nxt = cur->next;
            ListNode *incur = anshead;
            
            if (anshead->next == nullptr) {
                if (cur->val < anshead->val) { // cur need to be head
                    cur->next = anshead;
                    anshead = cur;
                    ansend = anshead->next;
                } else { // cur need to be after anshead
                    anshead->next = cur;
                    cur->next = nullptr;
                    ansend = cur;
                }
            } else if (ansend->val < cur->val) {
                ansend->next = cur;
                cur->next = nullptr;
                ansend = cur;
            } else {
                if (cur->val < anshead->val) {
                    cur->next = anshead;
                    anshead = cur;
                } else {
                    while (incur->next != nullptr && incur->next->val < cur->val)
                        incur = incur->next;
                    ListNode *innxt = incur->next;
                    incur->next = cur;
                    cur->next = innxt;
                    if (cur->next == nullptr)
                        ansend = cur;
                }    
            }
            cur = nxt;
        }
        return anshead;
    }
};
