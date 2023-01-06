/**
 * Title:  Maximum Ice Cream Bars (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, Janurary, 2023
 */

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int ans = 0;
        sort(costs.begin(), costs.end());
        for (int i = 0; i < n; i++) {
            coins -= costs[i];
            if (coins < 0)
                break;
            ans += 1;
        }
        return ans;
    }
};
