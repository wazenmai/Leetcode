/**
 * Title:  Stone Game II (Leetcode Medium 1140)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Method: DP. dp[i][m] = the maximum value that player can get starting from i-th piles, capable to take 1 ~ 2m piles
 * Result: Time complexity O(n^3), Space complexity O(n^2).
 * Date:   20, August, 2024
 */

class Solution {
public:
    int turn(int cur, int m, vector<int>& suffix_sum, vector<vector<int>>& dp) {
        if (cur + 2 * m >= suffix_sum.size()) return suffix_sum[cur];
        if (dp[cur][m] != -1) return dp[cur][m];

        // for the next turn, we want our opponent get minimum profit
        int opponent = INT_MAX;
        for (int x = 1; x <= 2 * m; x++) {
            opponent = min(opponent, turn(cur + x, max(x, m), suffix_sum, dp));
        }
        return dp[cur][m] = suffix_sum[cur] - opponent;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        // compute suffix sum
        vector<int> suffix_sum = piles;
        for (int i = n - 2; i >= 0; i--) {
            suffix_sum[i] += suffix_sum[i + 1];
        }

        // dp[i][m] = the maximum value that player can get starting from i-th piles, capable to take 1 ~ 2m piles
        // dp[i][m] = dp[i + x][max(m, x)] for x = 1 ~ 2m
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return turn(0, 1, suffix_sum, dp);
    }
};

// Time complexity
// - computing suffix sum: O(n)
// - computing max stones
//   - We need to compute all state in memo, cur=0 ~ n, and m = 1 ~ n. So total state is O(n^2)
//   - In each state, we iterate from i = 1 ~ 2 *m, so this is O(n)
//   - O(n^2) * O(n) = O(n^3)
