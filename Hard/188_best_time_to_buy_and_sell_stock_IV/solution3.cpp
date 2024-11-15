/**
 * Title:  Best Time to Buy and Sell Stock IV (Leetcode Hard 188)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, November, 2024
 * Method: Memory Optimization, for every day's buy and sell, we only record the previous day's buy and sell. We don't need to record all the days' buy and sell.
 * Result: Time complexity O(n * k), space complexity O(k).
 */


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int state = k * 2 + 1;
        vector<int> cur(state, -1000);
        cur[0] = 0; // no stock
        cur[1] = -prices[0]; // buy stock
        for (int i = 1; i < n; i++) { // day
            int temp0 = cur[0], temp1;
            for (int j = 1; j < state; j += 2) {
                temp1 = cur[j];
                cur[j] = max(cur[j], temp0 - prices[i]); // buy
                temp0 = cur[j + 1];
                cur[j + 1] = max(cur[j + 1], temp1 + prices[i]); // sell
            }
        }
        return (int)*max_element(cur.begin(), cur.end());
    }
};
// 0 transaction - no stock 0, buy stock 1
// 1 transaction - no stock 2, buy stock 3
// ...
// k transaction - no stock

// 2, 4, 1
// 0 no stock       0       0
// 1 have stock     -2      -2
// 2 no stock, 1    -1000   2
// 3 have stock, 1. -1000   -1000
// 4 no stock 2     -1000
