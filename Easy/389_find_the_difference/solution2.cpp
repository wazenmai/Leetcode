/**
 * Title:  Find the Difference (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   7, Feb, 2022
 * Method: Use vector instread of unordered_map
 */

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> hash_table(26, 0);
        for (auto& c : s) {
            hash_table[c - 'a'] += 1;
        }
        for (auto& c : t) {
            if (hash_table[c - 'a'] == 0)
                return c;
            hash_table[c - 'a'] -= 1;
        }
        return t[0];
    }
};
