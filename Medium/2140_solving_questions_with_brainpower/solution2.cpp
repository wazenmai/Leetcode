/**
 * Title:  Solving Questions with Brainpower (Leetcode Medium 2140)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, December, 2024
 * Method: Memory Optimization. dp[i] = max point I can get from i ~ n - 1
 * Result: Time complexity O(n). Space complexity O(n).
 */

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0);
        dp[n - 1] = questions[n - 1][0];
        
        for (int i = n - 2; i >= 0; i--) {
            int point = questions[i][0], cost = questions[i][1];
            long long solve = point;
            if (i + cost + 1 < n)
                solve += dp[i + cost + 1];
            long long not_solve = dp[i + 1];
            dp[i] = max(solve, not_solve);
            // cout << i << " (" << point << "," << cost << "): " << dp[i][0] << ", " << dp[i][1] << "\n";
        }
        return dp[0];
    }
};
// (3, 2), (4, 3), (4, 4) (2, 5)

// dp[i][0] = max point I can get from i ~ n - 1 and solve question[i]
// dp[i][0] = point[i] + max(dp[i + cost[i] + 1][1], dp[i + cost[i] + 1][0])

// dp[i][1] = max point I can get from 0 ~ i and did not solve quesiton[i]
// dp[i][1] = max(dp[i + 1][0], dp[i + 1][1])


// Optimization
// dp[i] = max point I can get from i ~ n - 1
