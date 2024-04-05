/**
 * Title:  Make The String Great (Leetcode Easy 1544)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, April, 2024
 */

class Solution {
public:
    bool isBad(char a, char b) {
        if (a >= 'a' && a <= 'z') {
            return a - 'a' + 'A' == b;
        }
        return a - 'A' + 'a' == b;
    }
    string makeGood(string s) {
        int n = s.length();
        int i = 0;
        while (i < n) {
            if (i <= n - 2 && isBad(s[i], s[i + 1])) {
                s.erase(i, 2);
                n -= 2;
                if (i != 0) i -= 1;
            } else {
                i++;
            }
        }
        return s;
    }
};
