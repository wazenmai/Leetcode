/**
 * Title:  Largest Substring Between Two Equal Characters (Leetcode Easy 1624)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, December, 2023
 */

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();
        int ans = -1;
        for (int i = 0; i < n - 1; i++) {
            for (int j = n - 1; j > i; j--) {
                if (s[i] == s[j]) {
                    if (i != j) ans = max(j - i - 1, ans);
                    else ans = max(0, ans);
                }
            } 
        }
        return ans;
    }
};
