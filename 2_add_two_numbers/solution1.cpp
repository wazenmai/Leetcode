/**
 * Title:  Add Two Numbers (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, Jan, 2021
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        ListNode *cur3 = new ListNode();
        ListNode *ans = cur3;
        int8_t carry = 0;
        while (cur1 != nullptr && cur2 != nullptr) {
            cout << cur1->val << " " << cur2->val << ' ';
            if (cur1->val + cur2->val + carry >= 10) {
                cur3->next = new ListNode(cur1->val + cur2->val + carry - 10);
                cur3 = cur3->next;
                carry = 1;
            } else {
                cur3->next = new ListNode(cur1->val + cur2->val + carry);
                cur3 = cur3->next;
                carry = 0;
            }
            
            if (cur1->next == nullptr && cur2->next != nullptr) {
                cout << "cur1\n";
                cur1->val = 0;
                cur2 = cur2->next;
            } else if (cur2->next == nullptr && cur1->next != nullptr) {
                cout << "cur2\n";
                cur2->val = 0;
                cur1 = cur1->next;
            } else {
                cout << '\n';
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
        }
        if (carry == 1) {
            cur3->next = new ListNode(1);
        }
        ans = ans->next;
        cur3 = ans;
        while(cur3 != nullptr) {
            cout << cur3->val << " ";
            cur3 = cur3->next;
        }
        return ans;
    }
};