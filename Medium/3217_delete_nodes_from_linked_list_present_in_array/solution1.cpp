/**
 * Title:  Delete Nodes From Linked List Present in Array (Leetcode Medium 3217)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, September, 2024
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> us;
        for (auto& num: nums) {
            us.insert(num);
        }
        ListNode* cur = head;
        ListNode* prev = cur;
        while (cur != nullptr) {
            if (us.find(cur->val) != us.end()) {
                if (cur == head) {
                    prev = head = cur->next;
                    cur = prev;
                } else {
                    prev->next = cur->next;
                    cur = prev->next;
                }
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
