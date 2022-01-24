/**
 * Title:  Linked List Random Node (Leetcode Medium 382)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   7, Jan, 2022
 * Result: 2 times faster than solution1
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
private:
    ListNode* node;
    int size;
public:
    Solution(ListNode* head) {
        ListNode* cur = head;
        node = head;
        size = 0;
        while (cur != nullptr) {
            cur = cur->next;
            ++size;
        }
    }
    
    int getRandom() {
        int r = rand() % size;
        ListNode* cur = node;
        while (r--) {
            cur = cur->next;
        }
        return cur->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
