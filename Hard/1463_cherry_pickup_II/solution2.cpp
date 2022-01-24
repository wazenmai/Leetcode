/**
 * Title:  Cherry Pickup II (Leetcode Hard 1463)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, Jan, 2022
 * Method: Dynamic programming
 * Result: Accepted
 */

class Solution {
private:
    int dp[72][72][72];
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp, -0x3f3f3f3f, sizeof(dp));
        dp[0][1][m] = grid[0][0] + grid[0][m-1];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < m; k++) {
                    int pre = -0x3f3f3f3f;
                    for (int jj = j; jj < j+3; jj++) {
                        for (int kk = k; kk < k+3; kk++) {
                            pre = max(pre, dp[i-1][jj][kk]);
                        }
                    }
                    if (j == k)
                        dp[i][j+1][k+1] = pre + grid[i][j];
                    else
                        dp[i][j+1][k+1] = pre + grid[i][j] + grid[i][k];
                }
            }
        }
        
        int ans = 0;
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                ans = max(ans, dp[n-1][j+1][k+1]);
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


// dp[i][j] = max(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]) + grid[i][j]
// dp[i][j][k] = the best reward with robot1 at (i, j), robot2 at (i, k)
//     j != k: max(dp[i-1][j'][k']) + grid[i][j] + grid[i][k]
//             j' = j-1, j, j+1
//             k' = k-1, k, k+1
//     j == k: max(dp[i-1][j'][k']) + grid[i][j]
// dp[0][0][cols-1] = grid[0][0] + grid[0][cols-1]
