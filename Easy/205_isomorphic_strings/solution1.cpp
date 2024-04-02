/**
 * Title:  Isomorphic Strings (Leetcode Easy 205)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, April, 2024
 * Method: Use two hash maps to record the mapping of two strings.
 * Result: Time complexity is O(n), space complexity is O(n).
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> t2s; // t -> s
        unordered_map<char, char> s2t; // s -> t
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (t2s.find(t[i]) == t2s.end()) {
                if (s2t.find(s[i]) != s2t.end() && s2t[s[i]] != t[i]) return false;
                t2s[t[i]] = s[i];
                s2t[s[i]] = t[i];
            } else if (t2s[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};
