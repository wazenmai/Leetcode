/**
 * Title:  Isomorphic Strings (Leetcode Easy 205)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, April, 2024
 * Method: Refactor the code in solution1.cpp
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> t2s; // t -> s
        unordered_map<char, char> s2t; // s -> t
        int n = s.length();
        for (int i = 0; i < n; i++) {
            // no two chars in t can map to same char in s
            if (s2t.find(s[i]) != s2t.end() && s2t[s[i]] != t[i]) return false;
            // a char in t cannot map to 2 char in s
            if (t2s.find(t[i]) != t2s.end() && t2s[t[i]] != s[i]) return false;
            // record the element map
            t2s[t[i]] = s[i];
            s2t[s[i]] = t[i];
        }
        return true;
    }
};
