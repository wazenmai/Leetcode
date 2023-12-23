/**
 * Title:  Path Crossing (Leetcode Easy 1496)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, December, 2023
 * Method: Use set to record the point (pair). Remember to add hash function for pair.
 */

// Hash function  
struct hashFunction  { 
  size_t operator()(const pair<int, int> &x) const { 
    return x.first ^ x.second; 
  } 
}; 

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<pair<int, int>, hashFunction> s;
        s.insert(make_pair(0, 0));
        pair<int, int> cur = make_pair(0, 0);
        for (auto& c: path) {
            if (c == 'N') {
                cur.first += 1;
            } else if (c == 'S') {
                cur.first -= 1;
            } else if (c == 'E') {
                cur.second += 1;
            } else {
                cur.second -= 1;
            }
            if (s.count(cur)) return true;
            s.insert(cur);
        }
        return false;
    }
};
