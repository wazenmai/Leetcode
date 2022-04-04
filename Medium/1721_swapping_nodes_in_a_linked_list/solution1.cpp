/**
 * Title:  Swapping Nodes in a Linked List (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, April, 2022
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *front, *back;
        int count = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            count++;
            if (count == k)
                front = cur;
            if (count > k)
                back = back->next;
            cur = cur->next;
        }
        if (front == back)
            return head;
        int temp = front->val;
        front->val = back->val;
        back->val = temp;
       return head;     
    }
};
