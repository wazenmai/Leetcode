/**
 * Title:  Middle of the Linked list (Leetcode Easy)
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
    ListNode* middleNode(ListNode* head) {
        ListNode *mid, *cur;
        int mid_id, size_id;

        cur = mid = head;
        mid_id = size_id = 1;
        while (cur->next != nullptr) {
            cur = cur->next;
            size_id += 1;
            if (mid_id != (size_id / 2 + 1)) {
                mid = mid->next;
                mid_id += 1;
            }
        }
        return mid;
    }
};

