/**
 * Title:  Solving Questions with Brainpower (Leetcode Medium 2140)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, December, 2024
 * Method: Dynamic Programming, please refer to the comments below.
 * Result: Time complexity O(n). Space complexity O(n).
 */

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<vector<long long>> dp(n, vector<long long>(2, 0)); // dp[i][0] = solved, dp[i][1] = not solved
        for (int i = n - 1; i >= 0; i--) {
            int point = questions[i][0], cost = questions[i][1];
            if (i + cost + 1 < n) {
                dp[i][0] = point + max(dp[i + cost + 1][0], dp[i + cost][1]);
            } else if (i + cost < n) {
                dp[i][0] = point + dp[i + cost][1];
            } else {
                dp[i][0] = point;
            }

            if (i + 1 < n) {
                dp[i][1] = max(dp[i + 1][0], dp[i + 1][1]);
            }
            // cout << i << " (" << point << "," << cost << "): " << dp[i][0] << ", " << dp[i][1] << "\n";
        }
        return max(dp[0][0], dp[0][1]);
    }
};
// (3, 2), (4, 3), (4, 4) (2, 5)

// dp[i][0] = max point I can get from i ~ n - 1 and solve question[i]
// dp[i][0] = point[i] + max(dp[i + cost[i] + 1][1], dp[i + cost[i] + 1][0])

// dp[i][1] = max point I can get from i ~ n - 1 and did not solve quesiton[i]
// dp[i][1] = max(dp[i + 1][0], dp[i + 1][1])
