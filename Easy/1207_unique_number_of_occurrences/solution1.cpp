/**
 * Title:  Unique Number of Occurrences (Leetcode Easy 1207)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, Janurary, 2024
 */

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int& e: arr) {
            m[e]++;
        }
        unordered_set<int> s;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (s.find(it->second) != s.end()) return false;
            s.insert(it->second);
        }
        return true;
    }
};
