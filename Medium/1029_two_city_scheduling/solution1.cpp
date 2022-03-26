/**
 * Title:  Two City Scheduling (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, Mar, 2022
 * Method: Sort the sequence by the difference btw cost_a and cost_b, you should choose the smaller cost with the bigger difference
 */

class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        int a_diff = a[1] - a[0];
        int b_diff = b[1] - b[0];
        return a_diff > b_diff;
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), compare);
        int n = (int)costs.size();
        int total = 0;
        for (int i = 0; i < n / 2; i++)
            total += costs[i][0];
        for (int i = n / 2; i < n; i++)
            total += costs[i][1];
        return total;
    }
};
