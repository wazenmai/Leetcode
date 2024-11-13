/**
 * Title:  Best Time to Buy and Sell Stock with Transcation Fee (Leetcode Medium 714)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, November, 2024
 * Method: DP. Memory Optimization.
 * Result: Time complexity O(n), space complexity O(1).
 */

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> cur(2, 0);
        vector<int> pre(2, 0);
        pre[1] = -prices[0];
        for (int i = 1; i < n; i++) {
            cur[0] = max(pre[0], pre[1] + prices[i] - fee);
            cur[1] = max(pre[1], pre[0] - prices[i]);
            pre = cur;
        }
        return max(cur[0], cur[1]);
    }
};

// dp[i][0] = have no stock on day i
// dp[i][1] = have stock on day i
