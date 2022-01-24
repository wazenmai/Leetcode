/**
 * Title:  Intersection of Two Linked Lists (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   8, Mar, 2021
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define NODES_SIZE 30005

ListNode *arr[NODES_SIZE];

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        
        int id = 0;
        while (headA != nullptr) {
            arr[id] = headA;
            headA = headA->next;
            id += 1;
        }
        while (headB != nullptr) {
            for (int i = 0; i < id; i++)
                if (headB == arr[i])
                    return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};
