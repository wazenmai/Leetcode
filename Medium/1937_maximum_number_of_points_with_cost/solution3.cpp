/**
 * Title:  Maximum Number of Points With Cost (Leetcode Medium 1937)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, August, 2024
 * Method: Use `dp` to store the maximum points we can get from "previous row".
 * Result: Time complexity O(n*3m) = O(nm), space complexity O(m).
 */

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<long long> dp(m, 0);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[j] += points[i][j];
                ans = max(ans, dp[j]);
            }

            long long max_pre = 0;
            // from left to right
            for (int j = 0; j < m; j++) {
                max_pre = dp[j] = max(max_pre - 1, dp[j]);
            }
            max_pre = 0;
            // from right to left
            for (int j = m - 1; j >= 0; j--) {
                max_pre = dp[j] = max(max_pre - 1, dp[j]);
            }
        }
        return ans;
    }
};
