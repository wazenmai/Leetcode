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

#define NODES_SIZE 10000

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
            return false;
        for (int i = 0; i < NODES_SIZE; i++) {
            if (head->next == nullptr)
                return false;
            else
                head = head->next;
        }
        return true;
    }
};

