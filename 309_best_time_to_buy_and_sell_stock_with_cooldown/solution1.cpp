/**
 * Title:  Best Time to Buy and Sell Stock with Cooldown (Leetcode Medium 309)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, May, 2021
 * Method: Maintain `buy`, `sell` and `rest`
 */

// buy: buy it or hold it
// rest: not holding any stock
// sell: sell the stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy, sell, rest;
        int prev_buy, prev_sell, prev_rest;
        int days = prices.size();
        buy = -prices[0];
        sell = -2000;
        rest = 0;
        
        if (days == 1)
            return 0;

        for (int i = 1; i < days; i++) {
            prev_buy = buy;
            prev_sell = sell;
            prev_rest = rest;
            buy = max(prev_rest - prices[i], prev_buy);
            rest = max(prev_rest, prev_sell);
            sell = prev_buy + prices[i];
            cout << "buy: " << buy << ", sell: " << sell << ", rest: " << rest << "\n";
        }
        return max(rest, sell);
    }
};
