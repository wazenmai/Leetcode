/**
 * Title:  Valid Anagram (Leetcode Easy 242)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, December, 2023
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);
        for (auto& c: s) {
            count[c - 'a']++;
        }
        for (auto& c: t) {
            if (count[c - 'a'] == 0) {
                return false;
            }
            count[c - 'a']--;
        }
        return (s.length() == t.length()) ? true : false;
    }
};
