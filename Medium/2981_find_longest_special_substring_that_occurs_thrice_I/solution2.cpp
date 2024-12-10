/**
 * Title:  Find Longest Special Substring That Occurs Thrice I (Leetcode Medium 2981)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, December, 2024
 * Method: Use 2D array since the string is only constructed by repetitive letters.
 * Result: Time complexity is O(n), space complexity is O(n).
 */
class Solution {
public:
    int maximumLength(string s) {
        int cnt[26][60] = {};
        int n = s.length();
        cnt[s[0] - 'a'][1] = 1;
        int ans = 0;
        int rep = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                rep++;
                for (int j = 1; j <= rep; j++) {
                    cnt[s[i] - 'a'][j]++;
                    if (cnt[s[i] - 'a'][j] >= 3) {
                        ans = max(ans, j);
                    }
                }
            } else {
                rep = 1;
                cnt[s[i] - 'a'][1]++;
                if (cnt[s[i] - 'a'][1] >= 3) {
                    ans = max(ans, 1);
                }
            }
        }
        return (ans == 0) ? -1 : ans;
    }
};
