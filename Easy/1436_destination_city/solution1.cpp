/**
 * Title:  Destination City (Leetcode Easy 1436)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, December, 2023
 */

class Solution {
public:
    void print(unordered_set<string>& u) {
        for (auto& e: u) {
            cout << e << ", ";
        }
        cout << "\n";
    }
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> seen;
        unordered_set<string> dst;
        for (auto& path: paths) {
            seen.insert(path[0]);
            if (seen.find(path[1]) == seen.end()) {
                dst.insert(path[1]);
            }
            if (dst.find(path[0]) != dst.end()) { // this is not dst
                dst.erase(path[0]);
                seen.insert(path[0]);
            }
            // print(dst);
        }
        string ans = "";
        for (auto& s: dst) {
            ans = s;
        }
        return ans;
    }
};
