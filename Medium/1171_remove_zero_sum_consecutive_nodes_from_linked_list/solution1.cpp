/**
 * Title:  Remove Zero Sum Consecutive Nodes from Linked List (Leetcode Medium 1171)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, March, 2024
 * Method: Use a vector to store values on LinkedList. Use map to find the sum of subsequences, if sum = 0, delete the nodes in the subsequence.
 *         Use original linkedlist to delete nodes.
 * Result: Runtime 114 ms, Memory 14.93 MB.
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

        cur = head;
        ListNode* prev = cur;
        int i = 0;
        while (cur != nullptr) {
            if (m.find(i) == m.end() || cur->val == 0) { // delete this node
                if (cur == head) {
                    head = head->next;
                    prev = head;
                } else {
                    prev->next = cur->next;
                }
            } else {
                prev = cur;
            }
            i++;
            cur = cur->next;
        }
        return head;
    }
};
