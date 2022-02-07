/**
 * Title:  Merge k Sorted Lists (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   5, Feb, 2022
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
    ListNode* merge2Lists(ListNode *l1, ListNode *l2) {
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        
        if (!cur1)
            return l2;
        if (!cur2)
            return l1;
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        while (cur1 && cur2) {
            // cout << cur1->val << " " << cur2->val << "\n";
            if (cur1->val <= cur2->val) {
                cur->next = cur1;
                cur1 = cur1->next;
            } else {
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
        }
        if (cur1)
            cur->next = cur1;
        else if (cur2)
            cur->next = cur2;
       
        return head->next;
    }
    
    void print_list(ListNode *head) {
        if (head == nullptr) {
            cout << "[]\n";
            return;
        }
        
        ListNode *cur = head;
        cout << "[";
        while (cur != nullptr) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << "]\n";
    }
        
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = (int)lists.size();
        if (n == 0)
            return nullptr;
        int turn = (n == 1) ? 1 : log10(n - 1) / log10(2) + 1;
        cout << n << " " << turn << "\n";
        
        int base = 1;
        for (int i = 1; i <= turn; i++) {
            for (int j = 0; j + base < n; j += base * 2) {
                // cout << "merge " << j << " and " << j + base << "\n";
                lists[j] = merge2Lists(lists[j], lists[j + base]);
            }
            base *= 2;
        }
        return lists[0];
    }
};
