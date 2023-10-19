/**
 * Title:  Backspace String Compare (Leetcode Medium 343)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, October, 2023
 * Method: Use erase function to decide whether two string are the same.
 * Result: Time complexity O(N), space complexity O(1).
 */

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.length();
        int m = t.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '#' && i == 0) {
                s.erase(0, 1);
                i = -1;
                n -= 1;
            } else if (s[i] == '#') {
                s.erase(i - 1, 2);
                n -= 2;
                i -= 2;
               
            }
            // cout << s << ", " << i << ", " << n << "\n";
        }
        // cout << s << "\n";
        for (int i = 0; i < m; i++) {
            if (t[i] == '#' && i == 0) {
                t.erase(0, 1);
                i = -1;
                m -= 1;
            } else if (t[i] == '#') {
                t.erase(i - 1, 2);
                m -= 2;
                i -= 2;
                
            }
            // cout << t << ", " << i << ", " << m << "\n";
        }
        // cout << t << "\n";
        if (s == t)
            return true;
        return false;
    }
};
