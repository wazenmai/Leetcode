/**
 * Title:  Best Time to Buy and Sell Stock IV (Leetcode Hard 188)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, May, 2021
 * Method: Maintain state machine
 * Result: Runtime Error
 */

// 0 -> (buy) -> 1 -> (sell) -> 2 -> (buy) -> 3 -> (sell) -> 4(End)
//(rest)       (rest)         (rest)        (rest)

class Solution {
private:
    int buy[105];
    int prev_buy[105];
    int sell[105];
    int prev_sell[105];
public:
    int maxProfit(int k, vector<int>& prices) {
        int days = prices.size();
        vector<int> buy(k, 0);
        vector<int> prev_buy(k, -prices[0]);
        vector<int> sell(k, 0);
        vector<int> prev_sell(k, 0);

        if (days == 1)
            return 0;

        for (int i = 1; i < days; i++) {
            buy[0] = max(prev_buy[0], -prices[i]);
            sell[0] = 0;
            for (int j = 0; j < k; j++) {
                prev_buy[j] = buy[j];
                prev_sell[j] = buy[j];

                buy[j] = max(prev_buy[j], prev_sell[j] - prices[i]);
                sell[j] = max(prev_sell[j], prev_buy[j-1] + prices[i]);
            }
        }

        int answer = 0;
        for (int i = 0; i < k; i++)
            answer = max(answer, sell[i]);
        return answer;
    }
};