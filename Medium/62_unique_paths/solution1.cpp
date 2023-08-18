/**
 * Title:  Unique Paths (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, August, 2023
 * Method: Bottom-Up DP. Time Complexity O(mn), Space Complexity O(mn)
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        int mod = 2e9;
        vector<vector<unsigned int>> dp(m, vector<unsigned int>(n, 0));
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int i = 0; i < n; i++)
            dp[0][i] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
        }
        return (int)dp[m-1][n-1];
    }
};

// state: dp[i][j] = ways to go to (i, j)
