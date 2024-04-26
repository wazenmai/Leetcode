/**
 * Title:  Minimum Falling Path Sum II (Leetcode Hard 1289)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, April, 2024
 * Result: Time complexity is O(n^2), space complexity is O(n).
 */

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
            dp[i] = grid[0][i];
        for (int i = 1; i < n; i++) {
            int min1 = 10000000, min2 = 10000000;
            int idx1 = -1, idx2 = -1;
            for (int j = 0; j < n; j++) {
                if (dp[j] < min1) {
                    min2 = min1;
                    idx2 = idx1;
                    min1 = dp[j];
                    idx1 = j;
                } else if (dp[j] < min2) {
                    min2 = dp[j];
                    idx2 = j;
                }
            }
            for (int j = 0; j < n; j++) {
                if (idx1 != j) {
                    dp[j] = min1 + grid[i][j];
                } else {
                    dp[j] = min2 + grid[i][j];
                }
            }
        }
        return *min_element(dp.begin(), dp.end());
    }
};
