/**
 * Title:  Design Hashset (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, April, 2022
 * Method: Use bool vector to construct hash set, O(1) time each operation, O(n) space. 
 */

class MyHashSet {
private:
    vector<bool> v;
public:
    MyHashSet(): v(1e6 + 1, false) {}
    
    void add(int key) {
        v[key] = true;
    }
    
    void remove(int key) {
        v[key] = false;
    }
    
    bool contains(int key) {
       return v[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
