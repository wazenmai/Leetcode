/**
 * Title:  Coin Change (Leetcode Medium 322)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, December, 2024
 * Method: Bottom-up DP. dp[j] = minimum # of coins to form j. dp[j] = min(dp[j], 1 + dp[j - coin]) if coin <= j.
 * Result: Time complexity is O(n * m), space complexity is O(m). m = amount, n = coins.size().
 */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        if (amount == 0) return 0;
        if (amount < coins.back()) return -1;
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;
        for (int& coin: coins) {
            for (int j = 1; j <= amount; j++) {
                if (coin <= j && dp[j - coin] != 1e9) {
                    dp[j] = min(dp[j], 1 + dp[j - coin]);
                }
            }
        }
        return (dp[amount] == 1e9) ? -1 : dp[amount];
    }
};

// dp[j] = minimum # of coins to form j
