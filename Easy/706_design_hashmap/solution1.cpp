/**
 * Title:  Design Hashmap (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, April, 2022
 */

struct Node {
    int key;
    int val;
    Node* next;
    Node(int x, int y): key(x), val(y), next(nullptr) {}
};

class MyHashMap {
private:
    vector<Node*> v;
    bitset<16> b;
    int num;
public:
    MyHashMap() : v(16384, nullptr) {
        for (int i = 0; i < 14; i++)
            b.set(i);
        num = (int)b.to_ulong();
    }
    
    void put(int key, int value) {
        int h = key & num;
        // cout << "put (" << key << ", " << value << "): at " << bitset<16>(h) << endl;
        if (v[h] == nullptr) {
            // cout << "  make new node\n";
            v[h] = new Node(key, value);
        } else {
            Node* cur = v[h];
            while (cur->next) {
                if (cur->key == key) {
                    cur->val = value;
                    return;
                }
                cur = cur->next;
            }
            if (cur->key == key) {
                cur->val = value;
                return;
            }
            cur->next = new Node(key, value);
        }
    }
    
    int get(int key) {
        int h = key & num;
        // cout << "get " << key << " from " << bitset<16>(h) << "\n";
        if (v[h] == nullptr) {
            return -1;
        } else {
            Node* cur = v[h];
            while (cur) {
                if (cur->key == key) {
                    return cur->val;
                }
                cur = cur->next;
            }
            return -1;
        }
    }
    
    void remove(int key) {
        int h = key & num;
        // cout << "remove " << key << " at " << bitset<16>(h) << endl;
        if (v[h] == nullptr) {
            return;
        } else {
            Node* cur = v[h];
            Node* pre = cur;
            while (cur) {
                if (cur->key == key) {
                    if (cur == v[h]) {
                        v[h] = cur->next;
                    } else {
                        pre->next = cur->next;
                    }
                    return;
                }
                pre = cur;
                cur = cur->next;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
