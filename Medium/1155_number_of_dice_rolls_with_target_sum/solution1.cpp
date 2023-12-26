/**
 * Title:  Number of Dice Rolls With Target Sum (Leetcode Medium 1155)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, December, 2023
 * Method: dp[n][target] = # of ways to get target with n dices. dp[n][target] = sum(dp[n - 1][target - X] * dp[1][X]) for X in [1, k].
 * Result: Time complexity O(n * k * target), space complexity O(n * target)
 */

class Solution {
private:
    long long ans = 0;
    int mod = 1e9 + 7;
public:
    int recur(int n, int k, int target, vector<vector<int>>& dp) {
        if (n == 1) return (target <= k) ? 1 : 0;
        if (dp[n][target] != -1) return dp[n][target];
        // cout << "recur " << n << " " << target << "\n";
        long long res = 0;
        for (int i = 1; i <= k; i++) {
            if (target - i <= 0) break;
            res += recur(n - 1, k, target - i, dp);
        }
        return dp[n][target] = res % mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        for (int i = 1; i <= min(k, target); i++) {
            dp[1][i] = 1;
        }
        ans = recur(n, k, target, dp);
        return ans % mod;
    }
};

// dp[n][target] = numRollsToTarget
// dp[1][6] = 1
// dp[n][target] = dp[n - 1][target - X] * dp[1][X]
