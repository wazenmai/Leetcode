/**
 * Title:  Merge In Between Linked Lists (Leetcode Medium 1669)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, March, 2024
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start = nullptr;
        ListNode* end = nullptr;
        ListNode* cur = list1;
        int i = 0;
        while (cur != nullptr) {
            if (i + 1 == a) {
                start = cur;
            }
            if (i == b) {
                end = cur->next;
            }
            i++;
            cur = cur->next;
        }
        start->next = list2;
        cur = list2;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = end;
        return list1;
    }
};
