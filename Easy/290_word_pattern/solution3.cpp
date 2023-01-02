/**
 * Title:  Word Pattern (Leetcode Easy 290)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, Jan, 2023
 */

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> p_map;
        map<string, char> s_map;
        int n = pattern.length();
        int j = 0;
        s = " " + s + " ";
        int s_n = s.length();
        for (int i = 0; i < n; i++) {
            string new_str = "";
            ++j;
            if (j >= s_n)
                return false;
            while (s[j] != ' ') {
                new_str += s[j];
                ++j;
            }
            // cout << pattern[i] << " " << new_str;
            if (p_map.find(pattern[i]) == p_map.end()) {
                if (s_map.find(new_str) != s_map.end()) {
                    return false;
                }
                p_map.insert({pattern[i], new_str});
                s_map.insert({new_str, pattern[i]});
            } else {
                if (p_map.at(pattern[i]) != new_str)
                    return false;
            }
        }
        if (j < s_n - 1)
            return false;
        return true;
    }
};