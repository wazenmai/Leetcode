/**
 * Title:  Split Linked List in Parts (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, September, 2023
 * Method: Time complexity O(n+k).
 */

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if (k == 1)
            return vector<ListNode*>{head};
        
        int n = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            n++;
            cur = cur->next;
        }
        // cout << n << "\n";
        
        vector<ListNode*> ans;
        if (n <= k) {
            cur = head;
            int i = 0;
            while (cur != nullptr) {
                ListNode* now = cur;
                cur = cur->next;
                now->next = nullptr;
                ans.emplace_back(now);
                i++;
            }
            while (++i <= k) {
                ans.emplace_back(nullptr);
            }
        } else {
            int r = n / k;
            int m = n % k;
            cur = head;
            for (int i = 0; i < m; i++) {
                ans.emplace_back(cur);
                for (int j = 1; j <= r; j++) {
                    cur = cur->next;
                }
                ListNode* now = cur;
                cur = cur->next;
                now->next = nullptr;
            }
            for (int i = 0; i < k - m; i++) {
                ans.emplace_back(cur);
                for (int j = 1; j < r; j++) {
                    cur = cur->next;
                }
                ListNode* now = cur;
                cur = cur->next;
                now->next = nullptr;
            }
        }
        return ans;
    }
};
