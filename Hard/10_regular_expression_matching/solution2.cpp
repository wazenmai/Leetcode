/**
 * Title:  Regular Expression Matching (Leetcode Hard 10)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, December, 2024
 * Method: dp[i][j] = whether s[i:] and p[j:] match. Top-down DP.
 * Result: Time complexity O(TP), Space complexity O(TP). T = s.length(), P = p.length().
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        function<bool(int, int)> dfs = [&](int i, int j) {
            if (dp[i][j] != -1) {
                return (dp[i][j]) ? true : false;
            }
            bool ans;
            if (j == m) {
                ans = (i == n);
            } else {
                bool first_match = (i < n && (p[j] == s[i] || p[j] == '.'));
                if (j + 1 < m && p[j + 1] == '*') {
                    bool zero_match = dfs(i, j + 2);
                    if (first_match) {
                        ans = zero_match || dfs(i + 1, j);
                    } else {
                        ans = zero_match;
                    }
                } else {
                    ans = first_match && dfs(i + 1, j + 1);
                }
            }
            dp[i][j] = ans ? 1 : 0;
            return ans;
        };

        return dfs(0, 0);
    }
};