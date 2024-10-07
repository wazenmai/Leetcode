/**
 * Title:  Minimum String Length After Removing Substrings (Leetcode Easy 2696)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, October, 2024
 * Method: Recursion.
 */

class Solution {
public:
    int minLength(string& s) {
        int n = s.length();
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == 'A' && s[i] == 'B') {
                string ns = s.substr(0, i - 1) + s.substr(i + 1);
                return minLength(ns);
            } else if (s[i - 1] == 'C' && s[i] == 'D') {
                string ns = s.substr(0, i - 1) + s.substr(i + 1);
                return minLength(ns);
            }
        }
        return n;
    }
};
