/**
 * Title:  Best Time to Buy and Sell Stock II (Leetcode Easy 122)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, May, 2021
 * Method: Maintain `hold` and `not_hold`
 */

// hold: keep hold it or sell it , it is from hold or buy
// not hold: keep not hold or buy it, it is from not hold or sell

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -30005;
        int not_hold = 0;
        int prev_hold, prev_not_hold;
        int days = prices.size();
        
        if (days == 1)
            return 0;

        for (int i = 0; i < days; i++) {
            prev_hold = hold;
            prev_not_hold = not_hold;

            if (i == 0) 
                not_hold = prev_not_hold;
            else
                not_hold = max(prev_not_hold, prev_hold + prices[i]);
            hold = max(prev_hold, prev_not_hold - prices[i]);

            cout << "hold: " << hold << ", not_hold: " << not_hold << "\n";
        }
        return not_hold;
    }
};
