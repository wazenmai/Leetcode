/**
 * Title:  Maximal Square (Leetcode Medium 221)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   3, May, 2021
 */

/**
 * Dynamic Programming
 * dp[i][j] = side length of largest 1's square that (i, j) is at left top 
 * dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1, if dp[i][j] == 1, else 0
 */

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();
        int dp[height][width];
        int ans = 0;

        for (int i = 0; i < width; i++) {
            dp[height - 1][i] = matrix[height - 1][i] - '0';
            ans = max(dp[height - 1][i], ans);
        }
        for (int i = height - 2; i >= 0; i--) {
            for (int j = width - 1; j >= 0; j--) {
                if (j == width - 1) {
                    dp[i][j] = matrix[i][j] - '0';
                } else {
                    if (matrix[i][j] == '1') {
                        dp[i][j] = min(dp[i + 1][j + 1], min(dp[i + 1][j], dp[i][j + 1])) + 1;
                    } else {
                        dp[i][j] = 0;
                    }
                }
                ans = max(dp[i][j], ans);
            }
        }
        return ans * ans;
    }
};
