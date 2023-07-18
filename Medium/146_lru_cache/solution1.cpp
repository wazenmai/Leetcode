/**
 * Title:  LRU Cache (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   018 July, 2023
 */

class LRUCache {
private:
    
public:
    class node {
        public:
            int key;
            int val;
            node* next;
            node* prev;
            node(int _key, int _val) {
                key = _key;
                val = _val;
                prev = next = nullptr;
            }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    int size;
    unordered_map<int, node*> m;
    
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node* newNode) {
        node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(node* delNode) {
        node* delprev = delNode->prev;
        node* delnext = delNode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key) {
        if (m.count(key)) {
            
            node* n = m[key];
            int cur = n->val;
            m.erase(key);
            deleteNode(n);
            addNode(n);
            m[key] = head->next;
            return cur;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (m.count(key)) {
            node* n = m[key];
            m.erase(key);
            deleteNode(n);
        }
        if (m.size() == size) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
