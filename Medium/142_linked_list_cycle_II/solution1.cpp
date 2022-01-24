/**
 * Title:  Linked List Cycle II (Leetcode Medium 142)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, Jan, 2022
 * Method: O(n) memory + O(n) time
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
        if (head == nullptr)
            return nullptr;
        vector<ListNode*> check;
        ListNode* cur = head;
        while (cur->next != nullptr) {
            check.emplace_back(cur);
            cur = cur->next;
            if (find(check.begin(), check.end(), cur) != check.end()) {
                return cur;
                break;
            }
        }
        return nullptr;
    }
};
