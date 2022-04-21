
/**
 * Title:  Design Hashset (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, April, 2022
 * Method: Use bit-manipulation (char) to construct hash set, O(1) time each operation. 
 */

class MyHashSet {
private:
    vector<char> v;
public:
    MyHashSet(): v(125001, 0) {}
    
    void add(int key) {
        int pos = key / 8;
        int bit = key % 8;
        v[pos] |= (1 << bit);
    }
    
    void remove(int key) {
        int pos = key / 8;
        int bit = key % 8;
        int num = (0xff ^ (1 << bit));
        v[pos] &= num;
    }
    
    bool contains(int key) {
        int pos = key / 8;
        int bit = key % 8;
        return (v[pos] & (1 << bit));
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */