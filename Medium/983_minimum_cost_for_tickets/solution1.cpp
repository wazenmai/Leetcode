/**
 * Title:  Minimum Cost For Tickets (Leetcode Medium 983)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, December, 2024
 * Method: dp[i] = min-cost to travel on days (0 ~ i). We use binary search to find the index of maximum day in days that <= days[i] - 30 or days[i] - 7.
 * Result: Time complexity is O(nlogn), where n is the size of days. Space complexity is O(n).
 */

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0);

        function<int(int)> bs = [&](int x) {
            if (x == 0) return 0;
            int l = 0, r = n;
            while (l < r) {
                int mid = (l + r) >> 1;
                // cout << "(" << l << "," << r << ") " << mid << "\n";
                if (days[mid] <= x) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return l;
        };

        for (int i = 0; i < n; i++) {
            if (days[i] >= 30) {
                dp[i + 1] = min(dp[bs(days[i] - 30)] + costs[2], min(dp[bs(days[i] - 7)] + costs[1], dp[i] + costs[0]));
            } else if (days[i] >= 7) {
                dp[i + 1] = min(costs[2], min(dp[bs(days[i] - 7)] + costs[1], dp[i] + costs[0]));
            } else {
                dp[i + 1] = min(costs[2], min(costs[1], dp[i] + costs[0]));
            }
            // cout << i << ": " << days[i] << "," << dp[i + 1] << "\n";
        }
        return dp[n];
    }
};


// dp[i] = min-cost to travel on days (0 ~ i)
// dp[i] = min(dp[i - 30] + costs[2], dp[i - 7] + costs[1], dp[i - 1] + costs[0])
// - use binary search to find the maximum number that <= i - 30

//  0 1   2. 3. 4. 5, 6
// [1, 4, 6, 7, 8, 20], [2,7,15] - 1

// find 3 -> 7 -> find 1 -> 4 -> find 0, l = 1
// 0. 1 dp[1] = 2
// 1. 4 dp[2] = 7 or 4
// 2. 6 dp[3] = 7 or 6
// 3. 7 dp[4] = 7 or 8
// 4. 8 dp[5] = 7+2 or 9
// dp[6] = 7 + 9 or 11 or 15


// [2,6,17,20,29], costs [3, 18, 61]
// 0. 2 dp[1] = 3
// 1. 6 dp[2] = 6
// 2. 17 dp[3] = 9
// 3. 20 dp[4] = 12
// 4. 29 dp[5] = dp[22]

// (0, 6) - 3 - 20, 22
// (4, 6) - 5
