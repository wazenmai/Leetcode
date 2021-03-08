/**
 * Title:  Linked List Cycle (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   8, Mar, 2021
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// In a cycle, if one always run faster than the other one, eventually he will reach her.

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
            return false;
        
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
