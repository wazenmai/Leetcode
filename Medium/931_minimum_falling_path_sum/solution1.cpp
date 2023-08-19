/**
 * Title:  Minimum Falling Path Sum (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, August, 2023
 */

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp = matrix[0];
        for (int i = 1; i < n; i++) {
            vector<int> new_dp(n);
            new_dp[0] = min(dp[0], dp[1]) + matrix[i][0];
            new_dp[n - 1] = min(dp[n - 2], dp[n - 1]) + matrix[i][n - 1];
            for (int j = 1; j < n - 1; j++) {
                new_dp[j] = min(min(dp[j - 1], dp[j]), dp[j + 1]) + matrix[i][j];
            }
            dp = new_dp;
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
            ans = min(dp[i], ans);
        return ans;
    }
};

// state: dp[i][j]: minimum sum to fall in (i, j)
// transition: dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) + matrix[i][j];
// board: dp[0] = matrix[0]
// Time complexity: O(n^2)
// Sapce complexity (optimization): O(n)
