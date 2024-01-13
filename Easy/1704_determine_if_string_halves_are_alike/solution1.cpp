/**
 * Title:  Determine if String Halves Are Alike (Leetcode Easy 1704)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, Janurary, 2024
 */

class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int i = 0, j = n / 2;
        int cnt1 = 0, cnt2 = 0;
        while (j < n) {
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                cnt1++;
            }
            if (s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U' || s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
                cnt2++;
            }
            i++;
            j++;
        }
        if (cnt1 == cnt2) return true;
        return false;
    }
};
