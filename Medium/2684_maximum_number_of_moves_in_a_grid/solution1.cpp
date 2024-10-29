/**
 * Title:  Maximum Number of Moves in a Grid (Leetcode Medium 2684)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, October, 2024
 * Method: DP. dp[i][j] = number of moves to reach(i, j). dp[i][j] = max(dp[pi][j - 1] + 1) if grid[pi][j - 1] < grid[i][j] && dp[pi][j - 1] > 0.
 * Result: Time complexity O(nm). Space complexity O(nm).
 */

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int temp = 0;
        for (int i = 0; i < n; i++) { // first column
            for (int k = -1; k <= 1; k++) {
                int pi = i + k;
                if (pi < 0 || pi >= n) continue;
                if (grid[pi][0] < grid[i][1]) {
                    dp[i][1] = 1;
                }
            }
            temp = max(temp, dp[i][1]);
        }
        if (temp == 0) return 0;
        for (int j = 2; j < m; j++) {
            int temp = 0;
            for (int i = 0; i < n; i++) {
                for (int k = -1; k <= 1; k++) {
                    int pi = i + k;
                    if (pi < 0 || pi >= n) continue;
                    if (dp[pi][j - 1] > 0 && grid[pi][j - 1] < grid[i][j]) {
                        dp[i][j] = max(dp[i][j], dp[pi][j - 1] + 1);
                    }
                }
                temp = max(temp, dp[i][j]);
                // cout << "(" << i << "," << j << "): " << dp[i][j] << "\n";
            }
            if (temp == 0) return j - 1;
        }
        return m - 1;
    }
};
