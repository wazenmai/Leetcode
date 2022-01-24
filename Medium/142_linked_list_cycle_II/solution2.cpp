/**
 * Title:  Linked List Cycle II (Leetcode Medium 142)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, Jan, 2022
 * Method: O(1) memory + O(n^2) time
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode* cur = head->next;
        ListNode* temp = head;
        int limit = 10000;
        while (limit-- && cur->next != nullptr) {
            if (temp == cur) {
                return temp;
            }
            if (!limit) {
                limit = 10000;
                temp = temp->next;
                cur = temp->next;
            }
            cur = cur->next;
        }
        
        return nullptr;
    }
};
