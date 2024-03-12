/**
 * Title:  Remove Zero Sum Consecutive Nodes from Linked List (Leetcode Medium 1171)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, March, 2024
 * Method: Same method as solution1.cpp, but create a new linkedlist to store the result.
 * Result: Runtime 113 ms, Memory 15.23 MB.
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> v;
        ListNode* cur = head;
        while (cur != nullptr) {
            v.emplace_back(cur->val);
            cur = cur->next;
        }

        unordered_map<int, int> m;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            bool flag = false;
            m[i] = v[i];
            for (int j = 0; j < i; j++) {
                if (m.find(j) != m.end()) {
                    m[j] += v[i];
                    if (m[j] == 0) {
                        for (int k = j; k <= i; k++) {
                            m.erase(k);
                        }
                        flag = true;
                    }
                }
                if (flag) {
                    break;
                }
            }
        }

        // for (auto it = m.begin(); it != m.end(); it++)
        //     cout << it->first << " ";
        // cout << "\n";

        cur = new ListNode();
        head = cur;
        for (int i = 0; i < n; i++) {
            if (m.find(i) != m.end() && v[i] != 0) {
                ListNode* temp = new ListNode(v[i]);
                cur->next = temp;
                cur = cur->next;
            }
        }
        return head->next;
    }
};
