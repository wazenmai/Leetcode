/**
 * Title:  Reorder List (Leetcode Medium 143)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, March, 2024
 * Method: Use fast and slow pointer to find the middle point of list. Reverse the right part of list. Then connect two list one by one.
 * Result: Time complexity O(n). Space complexity O(1).
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
    void reorderList(ListNode* head) {
        // Find mid point of linked list
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;

        // Reverse right part of linked list
        ListNode* cur = mid;
        ListNode* prev = nullptr;
        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        
        // Concat two list one by one
        ListNode* l1 = head;
        ListNode* l2 = prev;
        while (l2 != nullptr) {
            ListNode* tmp1 = l1->next;
            ListNode* tmp2 = l2->next;
            l1->next = l2;
            l2->next = tmp1;
            l1 = tmp1;
            l2 = tmp2;
        }
    }
};
