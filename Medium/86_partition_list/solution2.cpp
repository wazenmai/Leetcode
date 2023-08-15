/**
 * Title:  Partition List (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, Aug, 2023
 * Method: Use two pointers, one for the head of the list which value >= x, the other for the tail of the list which value < x. Time Complexity O(n). Space Complexity O(1)
 */

class Solution {
public:
    void printList(ListNode* head) {
        ListNode* cur = head;
        while (cur != nullptr) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << "\n";
    }
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* tail = nullptr; // head of the list which value >= x
        ListNode* tail_cur = nullptr;
        ListNode* cur = head;
        ListNode* prev = head; // previous node of cur which value < x
        while (cur != nullptr) {
            if (cur->val >= x) {
                if (tail == nullptr) {
                    tail = tail_cur = cur;
                } else {
                    tail_cur->next = cur;
                    tail_cur = tail_cur->next;
                }
                if (head == cur) {
                    head = head->next;
                    cur->next = nullptr;
                    prev = cur = head;
                } else {
                    prev->next = cur->next;
                    cur->next = nullptr;
                    cur = prev->next;
                }
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        if (head)
            prev->next = tail;
        else
            head = tail;
        return head;
    }
};
