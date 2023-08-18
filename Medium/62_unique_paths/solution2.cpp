/**
 * Title:  Unique Paths (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, August, 2023
 * Method: Bottom-Up DP with memory optimization. Time Complexity O(mn), Space Complexity O(2n)
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        int mod = 2e9;
        vector<unsigned int> dp(n, 1);
        for (int i = 1; i < m; i++) {
            vector<unsigned int> new_dp(n, 0);
            new_dp[0] = 1;
            for (int j = 1; j < n; j++) {
                new_dp[j] = (dp[j] + new_dp[j - 1]) % mod;
            }
            dp = new_dp;
        }
        return (int)dp[n-1];
    }
};
