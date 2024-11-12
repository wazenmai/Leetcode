/**
 * Title:  Best Time to Buy and Sell Stock with Cooldown (Leetcode Medium 309)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, November, 2024
 * Method: Since we only need the current day, the previous day and the day before the previous day, we can optimize the space complexity to O(1).
 * Result: Time complexity O(n), space complexity O(1).
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1) return 0;
        vector<int> cur(2, 0);
        vector<int> pre(2, 0);
        vector<int> ppre(2, 0);
        pre[1] = -prices[0];
        if (n > 1) {
            cur[0] = max(pre[0], pre[1] + prices[1]);
            cur[1] = max(pre[1], -prices[1]);
            ppre = pre;
            pre = cur;
        }
        for (int i = 2; i < n; i++) {
            cur[0] = max(pre[0], pre[1] + prices[i]); // no stock - either continue no stock or sell the stock
            cur[1] = max(pre[1], ppre[0] - prices[i]); // have stock - either continue hold stock or buy the stock
            ppre = pre;
            pre = cur;
        }
        return max(cur[0], cur[1]);
    }
};

// dp[i][0] = have no stock on day i
// dp[i][1] = have stock on day i