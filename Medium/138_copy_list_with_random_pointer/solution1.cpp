/**
 * Title:  Copy List with Random Pointer (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, Mar, 2022
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return head;
        Node* arr[1001] = {nullptr};
        Node* newarr[1001] = {nullptr};
        Node* cur = head;
        unordered_map<Node*, int> ht; // pointer, index
        int n = 0;
        while (cur) {
            arr[n] = cur;
            ht[cur] = n;
            n++;
            cur = cur->next;
        }
        Node* newHead = new Node(head->val);
        cur = newHead;
        for (int i = 0; i < n - 1; i++) {
            cur->next = new Node(arr[i + 1]->val);
            newarr[i] = cur;
            cur = cur->next;
        }
        cur->next = nullptr;
        newarr[n - 1] = cur;
        cur = newHead;
        for (int i = 0; i < n; i++) {
            cur->random = (arr[i]->random) ? newarr[ht[arr[i]->random]] : nullptr; 
            cur = cur->next;
        }
        return newHead;
    }
};
