/**
 * Title:  Design Hashset (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, April, 2022
 * Method: Use vector to construct hash set, O(n) time each operation. 
 */

class MyHashSet {
private:
    vector<int> v;
public:
    MyHashSet() {}
    
    void add(int key) {
        auto it = find(v.begin(), v.end(), key);
        if (it == v.end())
            v.emplace_back(key);
    }
    
    void remove(int key) {
        auto it = find(v.begin(), v.end(), key);
        if (it != v.end())
            v.erase(it);
    }
    
    bool contains(int key) {
        auto it = find(v.begin(), v.end(), key);
        if (it == v.end())
            return false;
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */