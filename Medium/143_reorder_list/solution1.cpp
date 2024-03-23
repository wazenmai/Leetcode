/**
 * Title:  Reorder List (Leetcode Medium 143)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, March, 2024
 * Method: Use a vector to store all the nodes, then reorder the list by connecting the first and the last node, the second and the second last node, and so on.
 * Result: Time complexity O(n). Space complexity O(n).
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
        vector<ListNode*> v;
        ListNode* cur = head;
        while (cur != nullptr) {
            v.emplace_back(cur);
            cur = cur->next;
        }
        int n = (int)v.size();
        cur = head;
        for (int i = 0; i < n / 2; i++) {
            ListNode* nxt = cur->next;
            ListNode* last = v[n - 1 - i];
            if (nxt == last) {
                nxt->next = nullptr;
                break;
            }
            cur->next = last;
            last->next = nxt;
            cur = nxt;
        }
        if (n&1) cur->next = nullptr;
    }
};
