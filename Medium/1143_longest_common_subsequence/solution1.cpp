/**
 * Title:  Longest Common Subsequence (Leetcode Medium 1143)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, Janurary, 2024
 * Method: Dp. if i == j: dp[i][j] = dp[i - 1][j - 1] + 1, else: dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])
 * Result: Time complexity O(NM). Space complexity O(NM)
 */

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[n][m];
    }
};

// dp(i, j)
// if s1[i] == s2[j]: dp[i, j] = dp[i - 1][j - 1] + 1
// if s1[i] != s2[j]: dp[i, j] = max(dp[i][j - 1], dp[i - 1][j])
