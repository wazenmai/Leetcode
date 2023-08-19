/**
 * Title:  Triangle (Leetcode Medium 120)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, Aug, 2023
 * Method: Bottom-Up DP with memory optimization. Time complexity O(n^2). Space complexity O(n).
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n + 1, 0);
        dp[0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            vector<int> new_dp(n + 1);
            new_dp[0] = dp[0] + triangle[i][0];
            new_dp[i] = dp[i - 1] + triangle[i][i];
            for (int j = 1; j < i; j++) {
                new_dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
            }
            dp = new_dp;
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
            ans = min(dp[i], ans);
        return ans;
    }
};
