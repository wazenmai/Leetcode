/**
 * Title:  Insert Delete GetRandom O(1) (Leetcode Medium 380)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, Janurary, 2024
 * Method: Use unordered_set to store the elements. Insert and remove are O(1) time complexity.
 * Result: Runtime 207 ms Memory 97.2 MB.
 */

class RandomizedSet {
private:
    unordered_set<int> s;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (s.find(val) != s.end()) return 0;
        s.insert(val);
        return 1;
    }
    
    bool remove(int val) {
        if (s.find(val) == s.end()) return 0;
        s.erase(val);
        return 1;
    }
    
    int getRandom() {
        return *next(s.begin(), rand() % s.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
