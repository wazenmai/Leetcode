/**
 * Title:  Design Hashset (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, April, 2022
 * Method: Use linked list to construct hash set, O(n) time each operation. 
 */

struct Node {
    int val;
    Node* next;
    Node(int x): val(x), next(nullptr) {}
};

class MyHashSet {
private:
    Node* head;
public:
    MyHashSet() {
        head = nullptr;
    }
    
    void add(int key) {
        if (head == nullptr) {
            head = new Node(key);
            return;
        } else {
            Node* cur = head;
            while (cur->next) {
                if (cur->val == key)
                    return;
                cur = cur->next;
            }
            if (cur->val == key)
                return;
            cur->next = new Node(key);
        }
    }
    
    void remove(int key) {
        if (head == nullptr)
            return;
        Node* cur = head;
        Node* pre = head;
        while (cur) {
            if (cur->val == key) {
                if (cur == head) {
                    head = head->next;
                } else {
                    pre->next = cur->next;
                }
                return;
            }
            pre = cur;
            cur = cur->next;
        }
    }
    
    bool contains(int key) {
        if (head == nullptr)
            return false;
        Node* cur = head;
        while (cur) {
            if (cur->val == key)
                return true;
            cur = cur->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
