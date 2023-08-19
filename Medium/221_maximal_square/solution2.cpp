/**
 * Title:  Maximal Square (Leetcode Medium 221)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, Aug, 2023
 * Method: Bottom-Up DP with memory optimization.
 */

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = matrix[0][i] - '0';
            ans = max(ans, dp[i]);
        }
        for (int i = 1; i < m; i++) {
            // cout << "line " << i << "\n";
            vector<int> new_dp(n, 0);
            new_dp[0] = matrix[i][0] - '0';
            ans = max(ans, new_dp[0]);
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '1') {
                    new_dp[j] = min(min(dp[j - 1], dp[j]), new_dp[j - 1]) + 1;
                    // cout << j << ": " << new_dp[j] << "\n";
                    ans = max(ans, new_dp[j] * new_dp[j]);
                }
            }
            dp = new_dp;
        }
        return ans;
    }
};

/*
1 1 1 1 0
1 1 1 1 0
1 1 1 1 1
1 1 1 1 1
0 0 1 1 1
*/

// dp[i][j]: (i, j) as right bottom corner, the largest square containing only 1
// if 1: dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1
