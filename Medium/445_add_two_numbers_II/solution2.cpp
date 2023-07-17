/**
 * Title:  Add Two Numbers II (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, July, 2023
 * Method: Use stack instead of reversed linked list. Time Complexity O(n) // n is the length of the longer linked list
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode* now = l1;
        while(now != nullptr) {
            s1.push(now->val);
            now = now->next;
        }
        now = l2;
        while(now != nullptr) {
            s2.push(now->val);
            now = now->next;
        }

        stack<int> s3;
        int c = 0;
        while(!s1.empty() || !s2.empty()) {
            if (s1.empty()) {
                int v = s2.top() + c;
                s3.push(v % 10);
                c = v / 10;
                s2.pop();
            } else if (s2.empty()) {
                int v = s1.top() + c;
                s3.push(v % 10);
                c = v / 10;
                s1.pop();
            } else {
                int v = s1.top() + s2.top() + c;
                s3.push(v % 10);
                c = v / 10;
                s1.pop();
                s2.pop();
            }
        }
        if (c > 0)
            s3.push(c);

        ListNode* ans = nullptr;
        now = nullptr;
        while (!s3.empty()) {
            if (ans == nullptr) {
                ans = now = new ListNode(s3.top());
            } else {
                now->next = new ListNode(s3.top());
                now = now->next;
            }
            s3.pop();
        }
        return ans;
    }
};
