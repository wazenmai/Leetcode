/**
 * Title:  Cherry Pickup II (Leetcode Hard 1463)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, Jan, 2022
 * Method: Dynamic programming
 * Result: Accepted, 16ms, faster than 99% of submission
 */

class Solution {
private:
    int dp[72][72][72];
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // cout << n << " " << m << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m + 1; j++) {
                dp[i][0][j] = 0;
                dp[i][j][0] = 0;
                dp[i][m+1][j] = 0;
                dp[i][j][m+1] = 0;
                dp[0][j][0] = 0;
                dp[0][0][j] = 0;
            }
        }
        // cout << "Initialization complete\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < m; k++) {
                    if (i == 0) {
                        dp[i+1][j][k] = 0;
                        dp[i+1][1][m] = grid[i][0] + grid[i][m-1];
                        continue;
                    }
                    if (j > i) {
                        dp[i+1][j+1][k+1] = 0;
                        continue;
                    }
                    if (k < m - 1 - i) {
                        dp[i+1][j+1][k+1] = 0;
                        continue;
                    }
                    
                    int pre = 0;
                    for (int jj = j-1; jj <= j+1; jj++) {
                        for (int kk = k-1; kk <= k+1; kk++) {
                            if (jj > i)
                                continue;
                            if (kk < m - 1 - i)
                                continue;
                            pre = max(pre, dp[i][jj+1][kk+1]);
                        }
                    }
                    // cout << "(" << i << ", " << j << ", " << k << "): " << pre;
                    if (j == k)
                        dp[i+1][j+1][k+1] = pre + grid[i][j];
                    else
                        dp[i+1][j+1][k+1] = pre + grid[i][j] + grid[i][k];
                    // cout << " " << dp[i+1][j+1][k+1] << "\n";
                }
            }
        }
        
        int ans = 0;
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                ans = max(ans, dp[n][j+1][k+1]);
            }
        }
        return ans;  
    }
};

// dp[i][j] = max(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]) + grid[i][j]
// dp[i][j][k] = the best reward with robot1 at (i, j), robot2 at (i, k)
//     j != k: max(dp[i-1][j'][k']) + grid[i][j] + grid[i][k]
//             j' = j-1, j, j+1
//             k' = k-1, k, k+1
//     j == k: max(dp[i-1][j'][k']) + grid[i][j]
// dp[0][0][cols-1] = grid[0][0] + grid[0][cols-1]
