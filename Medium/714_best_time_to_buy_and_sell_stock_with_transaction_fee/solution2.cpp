/**
 * Title:  Best Time to Buy and Sell Stock with Transcation Fee (Leetcode Medium 714)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, November, 2024
 * Method: DP.
 * Result: Time complexity O(n), space complexity O(n).
 */

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee); // either continue not hold or sell from yesterday.
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); // either continue hold or buy from yesterday.
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};

// dp[i][0] = have no stock on day i
// dp[i][1] = have stock on day i