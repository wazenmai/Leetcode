/**
 * Title:  Minimum Number of Changes to Make Binary String Beautiful (Leetcode Medium 2914)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, November, 2024
 */

class Solution {
public:
    int minChanges(string& s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i += 2) {
            if (s[i] != s[i + 1]) {
                ans++;
            }
        }
        return ans;
    }
};
