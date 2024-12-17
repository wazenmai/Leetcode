/**
 * Title:  Regular Expression Matching (Leetcode Hard 10)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, December, 2024
 * Method: dp[i][j] = whether s[i:] and p[j:] match. Bottom up DP. If p[j + 1] == '*', we need to check zero match and first match of rest string (i + 1, j).
 * Result: Time complexity O(TP), Space complexity O(TP). T = s.length(), P = p.length().
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[n][m] = true;
        for (int i = n; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                bool first_match = (i < n && (p[j] == s[i] || p[j] == '.'));
                if (j + 1 < m && p[j + 1] == '*') {
                    dp[i][j] = dp[i][j + 2] || (first_match && dp[i + 1][j]);
                } else {
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};

// dp[i][j] = whether dp[i:] and dp[j:] match

// s = mississippi, p = mis*is*ip*.

// dp[1][1] = false
// dp[1][2] = true
// dp[1][3]
// dp[2][1]
// dp[2][2]

// dp[i][j] = whether s[0 ~ i] match p[0 ~ j]
// ans: dp[n][m]
// dp[i][j] =
// - p[j] = character, dp[i - 1][j - 1] && (s[i] == p[j])
// - p[j] = '.', dp[i - 1][j - 1]
// - p[j] = '*', search for previous element and check dp[i - 1][j - 1] && (s[i] == p[j])
// bounding case dp[0][0] = true, dp[0][j] = true