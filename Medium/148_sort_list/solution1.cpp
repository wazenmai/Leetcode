/**
 * Title:  Sort List (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, Feb, 2022
 * Result: TLE (O(N^2)), needs to be O(NlogN)
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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode *cur = head;
        ListNode *pre = head;
        ListNode *small_cur = head;
        ListNode *small_pre = head;
        ListNode *newHead = nullptr;
        ListNode *newcur = nullptr;
        int minimum = 100000;
        
        while (head != nullptr) {
            while (cur != nullptr) {
                if (cur->val < minimum) {
                    minimum = cur->val;
                    if (pre == cur)
                        small_pre = nullptr;
                    else
                        small_pre = pre;
                    small_cur = cur;
                }
                pre = cur;
                cur = cur->next;
            }
            if (newHead == nullptr) {
                if (small_cur == head) {
                    head = head->next;
                } else {
                    pre->next = head;
                    head = small_cur->next;
                    small_pre->next = nullptr;
                }
                newHead = small_cur;
                small_cur->next = nullptr;
                newcur = newHead;
            } else {
                if (small_cur == head) {
                    head = head->next;
                    
                } else {
                    pre->next = head;
                    head = small_cur->next;
                    small_pre->next = nullptr;
                }
                newcur->next = small_cur;
                small_cur->next = nullptr;
                newcur = small_cur;
            }
            minimum = 100000;
            cur = head;
            pre = head;
        }
        return newHead;
    }
};
