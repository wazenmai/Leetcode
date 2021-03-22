/**
 * Title:  Partition List (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   8, Mar, 2021
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *new_list, *new_cur;
        ListNode *cur, *temp, *prev;
        new_list = new_cur = temp = nullptr;
        cur = prev = head;
        
        // add node(value < x) to new list
        while (cur != nullptr) {
            if (cur->val < x) {
                
                // make node to new list
                if (!new_list) {
                    new_list = new ListNode(cur->val);
                    new_cur = new_list;
                } else {
                    new_cur->next = new ListNode(cur->val);
                    new_cur = new_cur->next;
                }

                // delete the node
                temp = cur;
                if (temp == head)
                    head = head->next;
                if (prev == cur) {
                    prev = prev->next;
                    cur = cur->next;
                } else {
                    cur = cur->next;
                    prev->next = cur;
                }
                delete temp;
                temp = nullptr;
                
            } else {
                if (prev != cur)
                    prev = prev->next;
                cur = cur->next;
            }
        }
        
        // in case we do not have value < x node
        if (new_list == nullptr) {
            new_list = head;
        } else {
            new_cur->next = head;
        }
        
        return new_list;
    }
};
