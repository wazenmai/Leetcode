/**
 * Title:  Linked List Random Node (Leetcode Medium 382)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   7, Jan, 2022
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
    vector<int> solution_list;
public:
    Solution(ListNode* head) {
        ListNode* cur = head;
        while (cur != nullptr) {
            solution_list.emplace_back(cur->val);
            cur = cur->next;
        }
    }
    
    int getRandom() {
        int n = solution_list.size();
        int r = rand() % n;
        // cout << n << " " << r << "\n";
        return solution_list[r];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
