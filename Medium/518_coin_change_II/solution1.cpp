/**
 * Title:  Coin Change II (Leetcode Medium 518)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, November, 2024
 * Method: DP Top-down.
 * Result: Time complexity O(n * amount), Space complexity O(n * amount).
 */

class Solution {
public:
    int helper(vector<int>& coins, vector<vector<int>>& dp, int i, int j) {
        // i: coins (0 ~ i), j: the amount
        if (i < 0 || j < 0) return 0; // no coin or no amount
        if (j == 0) return 1; // take all of the money
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = helper(coins, dp, i - 1, j) + helper(coins, dp, i, j - coins[i]);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return helper(coins, dp, n - 1, amount);
    }
};

// dp[i][j] = # of ways make up j from coins (0 ~ i)
// dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]]
// 1. # of ways make up j from coins (0 ~ i - 1)
// 2. # of ways make up j - coins[i] from coins (0 ~ i)
