/**
 * Title:  Best Time to Buy and Sell Stock I (Leetcode Easy 121)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, May, 2021
 * Method: Maintain minimum
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        int days = prices.size();

        if (days == 1)
            return 0;
        for (int i = 1; i < days; i++) {
            if (prices[i] - buy > profit)
                profit = prices[i] - buy;
            if (prices[i] < buy)
                buy = prices[i];
        }
        return profit;
    }
};
