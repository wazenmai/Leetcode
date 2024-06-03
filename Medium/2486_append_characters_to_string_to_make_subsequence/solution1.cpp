/**
 * Title:  Append Characters to String to Make Subsequence (Leetcode Medium 2486)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, June, 2024
 */

class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        int n = t.length();
        for (auto& c: s) {
            if (c == t[i]) {
                i++;
            }
            if (i == n)
                break;
        }
        return n - i;
    }
};
