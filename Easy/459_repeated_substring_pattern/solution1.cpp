/**
 * Title:    Repeated Substring Pattern (Leetcode Easy)
 * Author:   Bronwin Chen <iotbwu0101@gmail.com>
 * Date:     21, August, 2023
 * Analysis: O(N^2)
 */

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        string sub = "";
        int i = 0;
        while (i < n / 2) {
            sub += s[i];
            // cout << "check " << sub << "\n";
            // check pos
            bool same = true;
            for (int j = i + 1; j < n; j += sub.length()) {
                // cout << "-- " << j << " " << s[j] << "\n";
                if (s[j] != sub[0]) {
                    same = false;
                    break;
                }
                if (j + sub.length() > n) {
                    same = false;
                    break;
                }
                for (int k = j + 1; k < j + sub.length(); k++) {
                    if (s[k] != sub[k - j]) {
                        same = false;
                        break;
                    }
                }
            }
            i++;
            if (same)
                return true;
        }
        return false;
    }
};
