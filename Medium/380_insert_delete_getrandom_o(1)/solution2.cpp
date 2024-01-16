/**
 * Title:  Insert Delete GetRandom O(1) (Leetcode Medium 380)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, Janurary, 2024
 * Method: Use vector to store the values and unredered_map to store the index of each value.
 * Result: Runtime 163 ms Memory 97.6 MB.
 */

class RandomizedSet {
private:
    unordered_map<int, int> m; // record number: index
    vector<int> v;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (m.find(val) != m.end()) return false;
        v.emplace_back(val);
        m[val] = v.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        
        int idx = m[val];
        int last_ele = v[v.size() - 1];
        swap(v[idx], v[v.size() - 1]);
        m[last_ele] = idx;
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
