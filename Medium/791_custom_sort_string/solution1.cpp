/**
 * Title:  Custom Sort String (Leetcode Medium 791)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, March, 2024
 * Method: Use unordred_map to store the freq. of each char in s.
 */

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> m;
        for (char c: s) {
            m[c]++;
        }
        string ans = "";
        for (char c: order) {
            if (m.find(c) != m.end()) {
                while (m[c]--) {
                    ans += c;
                }
                m.erase(c);
            }
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            while (it->second--) {
                ans += it->first;
            }
        }
        return ans;
    }
};
