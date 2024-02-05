/**
 * Title:  First Unique Character in a String (Leetcode Easy 387)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, February, 2024
 */

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cnt(26, 0);
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            // cout << i << " " << ans << "\n";
            cnt[s[i] - 'a']++;

            while (cnt[s[ans] - 'a'] != 1) {
                ans++;
                if (ans > i) break;
            }
        }
        return (ans >= n) ? -1 : ans;
    }
};
