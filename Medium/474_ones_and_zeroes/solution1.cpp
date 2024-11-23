/**
 * Title:  Ones and Zeros (Leetcode Medium 474)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, November, 2024
 * Method: 3D DP. Please see explanation below.
 * Result: Time complexity O(m*n*len(strs)), space complexity O(m*n*len(strs)).
 */

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s_len = strs.size();
        vector<vector<vector<int>>> dp(s_len + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for (int i = 0; i < s_len; i++) {
            int zeros = 0, ones = 0;
            for (auto& c: strs[i]) {
                zeros += (c == '0');
                ones += (c == '1');
            }
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    if (j - zeros < 0 || k - ones < 0)
                        dp[i + 1][j][k] = dp[i][j][k];
                    else
                        dp[i + 1][j][k] = max(dp[i][j][k], dp[i][j - zeros][k - ones] + 1);
                }
            }
        }
        int ans = 0;
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= n; k++) {
                ans = max(ans, dp[s_len][j][k]);
            }
        }
        return ans; 
    }
};

// dp[i][j][k] = # of largest subset with j 0's and k 1's
// strs[i] = [zero_i, one_i], not take i, take i
// dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - zero_i][k - zero_i])


// Questions
// 1. What is the max # of subset if I'm at index i?
// 2. How can I achieve this answer by take index i or not take index i
