/**
 * Title:  Swap Nodes in Pairs (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, Feb, 2022
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = head;
        ListNode* vor = head;
        int counter = 2;
        while (cur != nullptr) {
            --counter;
            if (counter == 0) {
                ListNode* temp = cur->next;
                if (pre == head) {
                    cur->next = pre;
                    pre->next = temp;
                    head = cur;
                    cur = temp;
                } else {
                    vor->next = cur;
                    cur->next = pre;
                    pre->next = temp;
                    vor = cur;
                    cur = temp;
                }
                counter = 2;
            } else {
                vor = pre;
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
