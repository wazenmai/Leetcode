/**
 * Title:  Copy List with Random Pointer (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, Mar, 2022
 * Method: Use unordered_map to map old node and new node.
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
            return nullptr;
        Node* cur = head;
        Node* newHead = new Node(0);
        Node* newcur = newHead;
        unordered_map<Node*, Node*> ht; // old node, new node
        while (cur) {
            newcur->next = new Node(cur->val);
            ht[cur] = newcur->next;
            cur = cur->next;
            newcur = newcur->next;
        }
        newcur->next = nullptr;
        newHead = newHead->next;
        cur = head;
        newcur = newHead;
        while (cur) {
            newcur->random = (cur->random) ? ht[cur->random] : nullptr;
            newcur = newcur->next;
            cur = cur->next;
        }
        return newHead;
    }
};
