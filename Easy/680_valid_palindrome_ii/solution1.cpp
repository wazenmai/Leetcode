/**
 * Title:  Valid Palindrome II (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, Apr, 2022
 */

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        int change = 0;
        bool ans;
        while (i < j) {
            // cout << s[i] << " " << s[j] << ", " << change << "\n";
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                if (i + 1 == j) {
                    i++;
                    change++;
                } else if (s[i + 1] == s[j]) {
                    i++;
                    change++;
                } else if (s[i] == s[j - 1]) {
                    j--;
                    change++;
                } else {
                    ans = false;
                    change += 2;
                    break;
                }
            }
        }
        if (change <= 1)
            return true;
        ans = false;
        change = 0;
        i = 0;
        j = s.length() - 1;
        while (i < j) {
            // cout << s[i] << " " << s[j] << ", " << change << "\n";
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                if (i + 1 == j) {
                    i++;
                    change++;
                } else if (s[i] == s[j - 1]) {
                    j--;
                    change++;
                } else if (s[i + 1] == s[j]) {
                    i++;
                    change++;
                } else {
                    return false;
                }
            }
        }
        if (change <= 1)
            return true;
        return false;
    }
};
