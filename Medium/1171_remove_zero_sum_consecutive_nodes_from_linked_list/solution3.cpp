/**
 * Title:  Remove Zero Sum Consecutive Nodes from Linked List (Leetcode Medium 1171)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, March, 2024
 * Method: Use a set to store the prefix sum, if the sum appeared again, means the subsequence sum = 0. Use a vector to store the left elements.
 * Result: Runtime 10 ms, Memory 15.09 MB.
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
        unordered_set<int> s; // stored sum, if appeared again means the subsequence sum = 0
        vector<int> v; // left elements

        ListNode* cur = head;
        int sum = 0; // current prefix sum
        s.insert(0);
        while (cur != nullptr) {
            v.emplace_back(cur->val);
            sum += cur->val;
            if (s.find(sum) != s.end()) { // this sum appeared in sequence before
                int temp = sum;
                while (!v.empty()) {
                    s.erase(sum);
                    sum -= v.back();
                    v.pop_back();
                    if (sum == temp) break;
                }
            }
            s.insert(sum);
            cur = cur->next;
        }
        
        cur = new ListNode();
        ListNode* ans = cur;
        for (auto& e: v) {
            ListNode* temp = new ListNode(e);
            cur->next = temp;
            cur = cur->next;
        }
        return ans->next;
    }
};
