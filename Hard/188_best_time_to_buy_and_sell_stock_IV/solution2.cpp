/**
 * Title:  Best Time to Buy and Sell Stock IV (Leetcode Hard 188)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, November, 2024
 * Method: Maintain pre (yesterday) price and cur (today's) price. even index is no stock, odd index is buy stock. There are total k * 2 + 1 states. (buy/sell + no stock at all).
 * Result: Time complexity O(n * k), space complexity O(k).
 */

class Solution {
public:
    void print(vector<int>& v) {
        for (auto& e: v){
            cout << e << ",";
        }
        cout << "\n";
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int state = k * 2 + 1;
        vector<int> pre(state, -1000);
        vector<int> cur(state, 0);
        pre[0] = 0; // no stock
        pre[1] = -prices[0]; // buy stock
        
        for (int i = 1; i < n; i++) { // day
            for (int j = 1; j < state; j += 2) {
                cur[j] = max(pre[j], pre[j - 1] - prices[i]); // buy
                cur[j + 1] = max(pre[j + 1], pre[j] + prices[i]); // sell
            }
            pre = cur;
            // cout << "day " << i << ": " << prices[i] << ": ";
            print(cur);
        }
        int ans = 0;
        for (int i = 0; i < state; i++) {
            ans = max(ans, cur[i]);
        }
        return ans;
    }
};
// 0 transaction - no stock, buy stock
// 1 transaction - no stock, buy stock
// ...
// k transaction - no stock
