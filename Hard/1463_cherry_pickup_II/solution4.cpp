/**
 * Title:  CHerry Pickup II (Leetcode Hard 1463)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, February, 2024
 * Method: Remove visit array by initializing dp with -1.
 * Result: Time complexity O(nm^2), Space complexity O(nm^2)
 */

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        if (m == 1) {
            for (int i = 0; i < n; i++)
                ans += grid[i][0];
            return ans;
        } else if (m == 2) {
            for (int i = 0; i < n; i++)
                ans += grid[i][0] + grid[i][1];
            return ans;
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        dp[0][0][m - 1] = grid[0][0] + grid[0][m - 1];
        for (int i = 1; i < n; i++) { // row
            // cout << "row " << i - 1 << "\n";
            for (int j = 0; j < m; j++) { // robot 1 cols
                for (int k = 0; k < m; k++) { // robot 2 cols
                    // 9 possible combination
                    if (dp[i - 1][j][k] == -1) continue;
                    for (int step1 = -1; step1 <= 1; step1++) { // next pos step of robot1
                        if (j + step1 < 0 || j + step1 >= m) continue;
                        for (int step2 = -1; step2 <= 1; step2++) { // next pos step of robot2
                            if (k + step2 < 0 || k + step2 >= m) continue;
                            if (j + step1 == k + step2) {
                                dp[i][j + step1][k + step2] = max(
                                    dp[i][j + step1][k + step2], 
                                    dp[i - 1][j][k] + grid[i][k + step2]);
                            } else {
                                dp[i][j + step1][k + step2] = max(
                                    dp[i][j + step1][k + step2], 
                                    dp[i - 1][j][k] + grid[i][k + step2] + grid[i][j + step1]);
                            }
                        }
                    }
                    // if (dp[i - 1][j][k] > 0) {
                        // cout << "(" << j << "," << k << "): " << dp[i - 1][j][k] << "\n";
                    // }
                }
            }
        }
        // cout << "last row\n";
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                ans = max(ans, dp[n - 1][j][k]);
                // cout << "(" << j << "," << k << "): " << dp[n - 1][j][k] << "\n";
            }
        }
        // cout << "ans: " << ans << "\n";
        return ans;
    }
};

// (i, j) -> left down, down, right down

// dp[i][j][k]: maximum cherries that both robots can take starting on the ith row,
// column j and column k
// dp[0][0][m - 1] = grid[0][0] + grid[0][m - 1];
// 
