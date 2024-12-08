/**
 * Title:  Minimum Cost For Tickets (Leetcode Medium 983)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, December, 2024
 * Method: dp[i] = min-cost to travel til day i. If the day is not in days, the cost is the same as dp[i - 1]. Otherwise, the cost is the minimum of dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2].
 * Result: Time complexity is O(max_day), where max_day is the maximum day in days. Space complexity is O(max_day).
 */

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int last = days.back();
        vector<int> dp(last + 1, 0);
        int i = 0;
        for (int day = 1; day <= last; day++) {
            if (day < days[i]) {
                dp[day] = dp[day - 1];
            } else {
                dp[day] = min({dp[day - 1] + costs[0], dp[max(0, day - 7)] + costs[1], dp[max(0, day - 30)] + costs[2]});
                i++;
            }
        }
        return dp[last];
    }
};
