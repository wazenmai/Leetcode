/**
 * Title:    Repeated Substring Pattern (Leetcode Easy)
 * Author:   Bronwin Chen <iotbwu0101@gmail.com>
 * Date:     21, August, 2023
 * Method:   If there is a repeated substring p in s, then let s = p*x, t = s + s delete first and last character, t = (p-first) + p*(2x-2) + (p-last).
 *           So if s is repeated substring, then x >= 2 -> (2x - 2) >= x -> x >= 2, so t must contain s.
 * Analysis: O(N)
 */

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        if (t.substr(1, t.size() - 2).find(s) != -1)
            return true;
        return false;
    }
};
