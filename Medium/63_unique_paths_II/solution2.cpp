/**
 * Title:  Maximum Ice Cream Bars (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, August, 2023
 * Method: Top-down DP. dp[i][j] = dp[i-1][j] + dp[i][j-1]. dp[i][j] = ways to walk to (i, j)
 */

class Solution {
public:
    void printDp(vector<vector<int>>& dp) {
        for (auto v: dp) {
            for (int d: v) {
                cout << d << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        // first step check
        if (obstacleGrid[0][0] == 1)
            return 0;
        if (obstacleGrid[0][0] == 0)
            dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            if (obstacleGrid[i][0] == 1)
                break;
            dp[i][0] = 1;
        }
        for (int j = 0; j < m; j++) {
            if (obstacleGrid[0][j] == 1)
                break;
            dp[0][j] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        // printDp(dp);
        return dp[n-1][m-1];
    }
};

