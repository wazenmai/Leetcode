/**
 * Title:  Best Time to Buy and Sell Stock with Transcation Fee (Leetcode Medium 714)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, May, 2021
 * Method: Maintain `buy` and `sell`
 */

// buy: from hold or buy it
// sell: from not_hold or sell it

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy, sell;
        int prev_buy, prev_sell;
        int days = prices.size();
        buy = -prices[0];
        sell = 0;
        
        if (days == 1)
            return 0;

        for (int i = 1; i < days; i++) {
            prev_buy = buy;
            prev_sell = sell;
            buy = max(prev_sell - prices[i], prev_buy);
            sell = max(prev_buy + prices[i] - fee, prev_sell);
            cout << "buy: " << buy << ", sell: " << sell << "\n";
        }
        return sell;
    }
};
