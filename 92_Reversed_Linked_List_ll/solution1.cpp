/**
 * Title:  Reverse Linked List (Leetcode Medium)
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right || head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *cur, *prev_l, *last_r, *l_node, *r_node;
        ListNode *prev, *nxt;
        int id = 1;
        
        cur = head;
        prev_l = last_r = l_node = r_node = nullptr;
        while (cur != nullptr) {
            if (id == left - 1) {
                prev_l = cur;
            } else if (id == left) {
                l_node = cur;
            } else if (id == right) {
                r_node = cur;
            } else if (id == right + 1) {
                last_r = cur;
                break;
            }
            cur = cur->next;
            id += 1;
        }
        cout << (!prev_l) ? prev_l->val : "ll" << " ";
        cout << (!l_node) ? l_node->val : "l" << " ";
        cout << (!prev_l) ? r_node->val : "r" << " ";
        cout << (!last_l) ? last_r->val : "rr" << " ";

        prev = r_node;
        cur = l_node;
        while (cur != nullptr) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            if (prev == r_node)
                break;
        }

        if (prev_l == nullptr) {
            head = r_node;
        } else {
            prev_l->next = r_node;
        }
        return head;
    }
};
