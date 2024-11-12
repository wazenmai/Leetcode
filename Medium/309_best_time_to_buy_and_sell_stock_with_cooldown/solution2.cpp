/**
 * Title:  Best Time to Buy and Sell Stock with Cooldown (Leetcode Medium 309)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, November, 2024
 * Method: For each day i, maintain three states: no stock, have stock, no stock and is cooldown. Then update the states according to the rules.
 * Result: Time complexity O(n), space complexity O(n).
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]); // no stock - either continue no stock or sell the stock
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] - prices[i]); // have stock - either continue hold stock or buy the stock
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][2]);
            // cout << i << ": (" << dp[i][0] << "," << dp[i][1] << "," << dp[i][2] << ")\n";
        }
        return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
    }
};

// dp[i][0] = have no stock on day i
// dp[i][1] = have stock on day i
// dp[i][2] = have no stock and is cooldown on day i