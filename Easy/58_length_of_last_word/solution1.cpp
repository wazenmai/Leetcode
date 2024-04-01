/**
 * Title:  Length of Last Word (Leetcode Easy 58)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, April, 2024
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int i = n - 1;
        while (s[i] == ' ') {
            i--;
        }
        int len = 0;
        while (i >= 0 && s[i] != ' ') {
            i--;
            len++;
        }
        return len;
    }
};
