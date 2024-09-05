/**
 * Title:  Find Missing Observations (Leetcode Medium 2028)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, September, 2024
 */

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int goal = mean * (m + n);
        int total = accumulate(rolls.begin(), rolls.end(), 0);
        goal -= total;
        if (6 * n < goal || 1 * n > goal) return {};
        int base = 1;
        while ((base + 1) * n <= goal) {
            base++;
        }
        vector<int> ans(n, base);
        goal -= base * n;
        for (int i = 0; i < goal; i++) {
            ans[i]++;
        }
        return ans;
    }
};
