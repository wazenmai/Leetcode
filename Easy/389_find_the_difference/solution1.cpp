/**
 * Title:  Find the Difference (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   7, Feb, 2022
 */

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> hash_table;
        unordered_map<char, int> hash_table2;
        for (auto& c : s) {
            hash_table[c] += 1;
        }
        for (auto& c : t) {
            if (!hash_table[c])
                return c;
            hash_table2[c] += 1;
            if (hash_table2[c] > hash_table[c])
                return c;
        }
        return t[0];
    }
};
