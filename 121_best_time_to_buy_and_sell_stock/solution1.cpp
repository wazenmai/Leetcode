/**
 * Title:  Best Time to Buy and Sell Stock I (Leetcode Easy 121)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, May, 2021
 * Method: Bruce Search
 * Result: TLE
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int max_profit = 0;
        int days = prices.size();
        for (int i = 0; i < days - 1; i++) {
            profit = 0 - prices[i];
            for (int j = i + 1; j < days; j++) {
                profit += prices[j];
                if (profit > max_profit)
                    max_profit = profit;
                profit -= prices[j];
            }
        }
        return max_profit;
    }
};
