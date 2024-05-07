/**
 * Title:  Double a Number Represented as a Linked List (Leetcode Medium 2816)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, May, 2024
 * Method: Use vector to store the double value of each node, then add them up from the end to the beginning.
 * Result: Time complexity is O(n), space complexity is O(n).
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
    ListNode* doubleIt(ListNode* head) {
        vector<int> v;
        ListNode* cur = head;
        while (cur != nullptr) {
            v.emplace_back(cur->val + cur->val);
            cur = cur->next;
        }
        int n = v.size();
        int add = 0;
        for (int i = n - 1; i >= 0; i--) {
            v[i] = v[i] + add;
            add = 0;
            if (v[i] >= 10) {
                add = 1;
                v[i] = v[i] - 10;
            }
        }
        cur = head;
        int i = 0;
        while (cur != nullptr) {
            cur->val = v[i];
            i++;
            cur = cur->next;
        }
        if (add > 0) {
            ListNode* node = new ListNode(add);
            node->next = head;
            head = node;
        }
        return head;
    }
};
