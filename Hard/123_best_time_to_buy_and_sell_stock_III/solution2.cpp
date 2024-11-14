/**
 * Title:  Best Time to Buy and Sell Stock III (Leetcode Hard 123)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, November, 2024
 * Method: DP with memory optimization.
 * Result: Time complexity O(n), space complexity O(1).
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> pre(5, 0);
        vector<int> cur(5, 0);
        pre[1] = -prices[0];
        pre[2] = pre[3] = pre[4] = -1e5;

        for (int i = 1; i < n; i++) {
            cur[1] = max(pre[1], pre[0] - prices[i]);
            cur[2] = max(pre[2], pre[1] + prices[i]);
            cur[3] = max(pre[3], pre[2] - prices[i]);
            cur[4] = max(pre[4], pre[3] + prices[i]);
            pre = cur;
        }
        return max(cur[0], max(cur[2], cur[4]));
    }
};

// dp[i][0] = no stock, no transaction
// dp[i][1] = have stock, no transaction
// dp[i][2] = no stock, one transaction
// dp[i][3] = have stock, one transaction
// dp[i][4] = no stock, two transaction

