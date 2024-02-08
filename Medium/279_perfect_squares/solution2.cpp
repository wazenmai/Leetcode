/**
 * Title:  Perfect Squares (Leetcode Medium 279)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, February, 2024
 * Method: DP. dp[i] = numSquares(i). dp[i] = min(dp[i], dp[i - j * j] + 1) for j * j <= i.
 * Result: Time complexity O(n * sqrt(n)), Space complexity O(n).
 */

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
