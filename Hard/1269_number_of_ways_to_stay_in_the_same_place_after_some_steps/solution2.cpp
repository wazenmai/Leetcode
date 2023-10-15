/**
 * Title:  Number of Ways to Stay In The Same Place After Some Steps (Leetcode Hard 1269)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, October, 2023
 * Method: Bottom-up Dp.         
 * Result: Time complexity O(steps * n). Space complexity O(steps * n).
 */

class Solution {
private:
    int n;
    unsigned int mod = 1e9 + 7;
public:
    int numWays(int steps, int arrLen) {
        if (arrLen > steps)
            n = steps / 2 + 1;
        else
            n = arrLen;
        cout << n << "\n";
        vector<vector<unsigned int>> dp(steps + 1, vector<unsigned int>(n, -1));
        for (int i = 1; i < n; i++)
            dp[0][i] = 0;
        dp[0][0] = 1;
        for (int step = 1; step <= steps; step++) {
            if (1 < n)
                dp[step][0] = (dp[step - 1][0] + dp[step - 1][1]) % mod;
            else
                dp[step][0] = dp[step - 1][0];
            for (int i = 1; i < n - 1; i++) {
                dp[step][i] = (dp[step - 1][i] + dp[step - 1][i + 1] + dp[step - 1][i - 1]) % mod;
            }
            if (n - 2 >= 0)
                dp[step][n - 1] = (dp[step - 1][n - 1] + dp[step - 1][n - 2]) % mod;
        }
        return (int)dp[steps][0];
    }
};

// r l
// s s

// r l s
// s s s
// s r l
// r s l

// r l s s
// s r l s
// r s l s
// s s s s

// r r l l
// r l r l
// s r s l
// r s s l