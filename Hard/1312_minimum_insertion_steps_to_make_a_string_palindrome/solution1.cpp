/**
 * Title:  Minimum Insertion Steps to Make a String Palindrome (Leetcode Hard 1312)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, November, 2024
 * Method: Compare LCS of s and reverse(s). The result is n - LCS(s, reverse(s)).
 * Result: Time complexity O(n^2), Space complexity O(n^2).
 */

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        string rs = s;
        reverse(rs.begin(), rs.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s[i] == rs[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
                max_len = max(max_len, dp[i + 1][j + 1]);
            }
        }
        return n - max_len;
    }
};
