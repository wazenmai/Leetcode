/**
 * Title:  Count Square Submatrices with All Ones (Leetcode Medium 1277)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, October, 2024
 * Method: DP. dp[i][j] represents the maximum side length of the square submatrices with all ones ending at (right-bottom corner) matrix[i][j].
 * Result: Time complexity O(nm). Space complexity O(nm).
 */

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    dp[i + 1][j + 1] = min(min(dp[i][j], dp[i][j + 1]), dp[i + 1][j]) + 1;
                    ans += dp[i + 1][j + 1];
                }
            }
        }
        return ans;
    }
};
