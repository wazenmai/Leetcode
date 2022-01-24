/**
 * Title:  Best Time to Buy and Sell Stock III (Leetcode Hard 123)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, May, 2021
 * Method: Maintain state machine
 */

// 0 -> (buy) -> 1 -> (sell) -> 2 -> (buy) -> 3 -> (sell) -> 4(End)
//(rest)       (rest)         (rest)        (rest)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s1, s2, s3, s4;
        int s1p, s2p, s3p, s4p;
        int days = prices.size();

        if (days == 1)
            return 0;

        s1 = -prices[0];
        s2 = s3 = s4 = -100005;
        for (int i = 1; i < days; i++) {
            s1p = s1;
            s2p = s2;
            s3p = s3;
            s4p = s4;
            s1 = max(s1p, -prices[i]);
            s2 = max(s2p, s1p + prices[i]);
            s3 = max(s3p, s2p - prices[i]);
            s4 = max(s4p, s3p + prices[i]);
            cout << s1 << " " << s2 << " " << s3 << " " << s4 << "\n";
        }
        return max(max(s4, s2), 0);
    }
};
