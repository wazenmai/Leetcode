/**
 * Title:  Best Time to Buy and Sell Stock with Cooldown (Leetcode Medium 309)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, November, 2024
 * Method: Optimize state to 2, have or no stock. If we want to buy stock, we need to start from two days ago.
 * Result: Time complexity O(n), space complexity O(n).
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = -prices[0];
        if (n > 1) {
            dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
            dp[1][1] = max(dp[0][1], -prices[1]);
        }
        for (int i = 2; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]); // no stock - either continue no stock or sell the stock
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]); // have stock - either continue hold stock or buy the stock
            // cout << i << ": (" << dp[i][0] << "," << dp[i][1] << "," << dp[i][2] << ")\n";
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};

// dp[i][0] = have no stock on day i
// dp[i][1] = have stock on day i