/**
 * Title:  Richest Customer Wealth (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, Jan, 2022
 */

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for (auto& man : accounts) {
            int wealth = 0;
            for (auto& bank : man) {
                wealth += bank;
            }
            maxWealth = max(maxWealth, wealth);
        }
        return maxWealth;
    }
};
