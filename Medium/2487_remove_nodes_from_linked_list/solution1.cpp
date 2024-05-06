/**
 * Title:  Remove Nodes From Linked List (Leetcode Medium 2487)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, May, 2024
 * Method: Use stack to store the value and parent node, if current value is larger than the top of stack, pop the stack until the top of stack is larger than current value. Then delete the nodes from the parent node to current node. If the parent node is nullptr, delete from head. If the parent node is not nullptr, delete from the parent node.
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
    ListNode* removeNodes(ListNode* head) {
        int maxn = 0;
        ListNode* prev = nullptr;
        ListNode* cur = head;
        stack<pair<int, ListNode*>> st; // val, parent
        int cur_id = 0;
        while (cur != nullptr) {
            // cout << cur_id << ", " << cur->val << "\n";
            ListNode* p = new ListNode(0);
            while (!st.empty() && st.top().first < cur->val) {
                p = st.top().second;
                st.pop();
            }
            // delete note from id to cur
            // cout << "delete: ";
            if (p == nullptr) { // delete from head
                ListNode* d = head;
                while (d != cur) {
                    // cout << d->val << ", ";
                    ListNode* nxt = d->next;
                    d->next = nullptr;
                    delete d;
                    d = nxt;
                }
                prev = nullptr;
                head = cur;
            } else if (p->val != 0) { // delete from middle
                ListNode* d = p->next;
                while (d != cur) {
                    // cout << d->val << ", ";
                    ListNode* nxt = d->next;
                    p->next = nxt;
                    d->next = nullptr;
                    delete d;
                    d = nxt;
                }
                prev = p;
            }
            // cout << "\n";
            st.push(make_pair(cur->val, prev));
            cur_id++;
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};
