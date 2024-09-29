/**
 * Title:  All O' one Data Structure (Leetcode Hard 432)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, September, 2024
 * Method: O(1) get minKey and maxKey. When inserting or deleting a key, we need to update the key count and the key set with that count.
 *  key_counts: a set to store all the counts of keys, since set is ordered, we can get the max and min key count in O(1) time
 *  m: a map which key is the count of key, value is a set of keys with that count, we can get the keys with a specific count in O(1) time
 *  cnt: a map to store the count of each key
 * Result: 98ms, beats 53.87% of C++ submissions
 */

class AllOne {
private:
    set<int> key_counts;
    unordered_map<int, unordered_set<string>> m; // key_count -> string
    unordered_map<string, int> cnt;
public:
    AllOne() {}
    
    void inc(string key) {
        if (cnt.find(key) == cnt.end()) {
            key_counts.insert(1);
            m[1].insert(key);
            cnt[key] = 1;
        } else {
            int old_cnt = cnt[key];
            int new_cnt = cnt[key] + 1;
            cnt[key]++;
            m[old_cnt].erase(key);
            m[new_cnt].insert(key);
            key_counts.insert(new_cnt);
            if (m[old_cnt].empty()) {
                key_counts.erase(old_cnt);
            }
        }
    }
    
    void dec(string key) {
        m[cnt[key]].erase(key);
        if (m[cnt[key]].empty()) key_counts.erase(cnt[key]);
        if (cnt[key] > 1) {
            m[cnt[key] - 1].insert(key);
            key_counts.insert(cnt[key] - 1);
        }
        cnt[key]--;
    }
    
    string getMaxKey() {
        if (key_counts.empty()) return "";
        int max_cnt = *key_counts.rbegin();
        return *(m[max_cnt].begin());
    }
    
    string getMinKey() {
        if (key_counts.empty()) return "";
        return *(m[*(key_counts.begin())].begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
