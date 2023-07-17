/**
 * Title:  Add Two Numbers II (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, July, 2023
 * Method: Reversed Linked List. Time Complexity O(n) // n is the length of the longer linked list
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
    ListNode* ans;
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* now = head;
        ListNode* nxt = head;
        while(now != nullptr) {
            nxt = now->next;
            now->next = pre;
            pre = now;
            now = nxt;
        }
        return pre;
    }

    void printList(ListNode* head) {
        ListNode* now = head;
        while(now != nullptr) {
            cout << now->val << " ";
            now = now->next;
        }
        cout << "\n";
    }

    int length(ListNode* head) {
        ListNode* now = head;
        int ans = 0;
        while (now != nullptr) {
            now = now->next;
            ans++;
        }
        return ans;
    }

    ListNode* add(ListNode* l1, ListNode* l2) {
        ListNode* n1 = l1;
        ListNode* n2 = l2;
        ListNode* pre = nullptr;
        int c = 0;
        while (n1 != nullptr & n2 != nullptr) {
            int new_c = (n1->val + n2->val + c) / 10;
            n1->val = (n1->val + n2->val + c) % 10;
            c = new_c;
            pre = n1;
            n1 = n1->next;
            n2 = n2->next;
        }
        while (c > 0 & n1 != nullptr) {
            int new_c = (n1->val + c) / 10;
            n1->val = (n1->val + c) % 10;
            c = new_c;
            pre = n1;
            n1 = n1->next;
        }
        if (c > 0 & n1 == nullptr) {
            pre->next = new ListNode(c);
        }
        return l1;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        // printList(l1);
        // printList(l2);
        ListNode* ans;
        if (length(l1) >= length(l2)) {
            ans = add(l1, l2);
        } else {
            ans = add(l2, l1);
        }
        return reverseList(ans);
    }
};
