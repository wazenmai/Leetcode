/**
 * Title:  Final Prices With a Special Discount in a Shop (Leetcode Easy 1475)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, December, 2024
 * Result: Time complexity O(n^2), Space complexity O(n).
 */

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int r = i + 1;
            while (r < n && prices[r] > prices[i]) {
                r++;
            }
            ans[i] = (r == n) ? prices[i] : prices[i] - prices[r];
        }
        return ans;
    }
};
