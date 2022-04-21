
/**
 * Title:  Design Hashset (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, April, 2022
 * Method: Use bit-manipulation to construct hash set, O(1) time each operation. 
 */

class MyHashSet {
private:
    vector<unsigned long> v;
public:
    MyHashSet(): v(31251, 0) {}
    
    void add(int key) {
        unsigned long pos = key / 32;
        unsigned long bit = key % 32;
        v[pos] |= (1 << bit);
    }
    
    void remove(int key) {
        unsigned long pos = key / 32;
        unsigned long bit = key % 32;
        unsigned long num = (0xffffffff ^ (1 << bit));
        v[pos] &= num;
    }
    
    bool contains(int key) {
        unsigned long pos = key / 32;
        unsigned long bit = key % 32;
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