/**
 * Title:  Palindromic Substrings (Leetcode Medium 647)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, February, 2024
 * Method: Expand from center. For each character, expand to left and right to check if it is a palindrome.
 * Result: Time complexity O(n^2), Space complexity O(1).
 */

class Solution {
private:
    string t;
    int check(int l, int r, int ans = 0) {
        while (l >= 0 && r <= t.size()) {
            if (t[l--] == t[r++]) ans++;
            else break;
        }
        return ans;
    }
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        t = s;
        for (int i = 0; i < n; i++) {
            ans += check(i, i); // odd palindrome
            ans += check(i, i + 1); // even length palindrome
        }
        return ans;
    }
};
