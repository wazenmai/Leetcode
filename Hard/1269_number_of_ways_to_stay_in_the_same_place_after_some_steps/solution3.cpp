/**
 * Title:  Number of Ways to Stay In The Same Place After Some Steps (Leetcode Hard 1269)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, October, 2023
 * Method: Bottom-up Dp with memory optimization.         
 * Result: Time complexity O(steps * n). Space complexity O(n).
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
        vector<unsigned int> dp(n, -1);
        vector<unsigned int> pre(n, -1);
        for (int i = 1; i < n; i++)
            pre[i] = 0;
        pre[0] = 1;
        for (int step = 1; step <= steps; step++) {
            if (1 < n)
                dp[0] = (pre[0] + pre[1]) % mod;
            else
                dp[0] = pre[0];
            for (int i = 1; i < n - 1; i++) {
                dp[i] = (pre[i] + pre[i + 1] + pre[i - 1]) % mod;
            }
            if (n - 2 >= 0)
                dp[n - 1] = (pre[n - 1] + pre[n - 2]) % mod;
            pre = dp;
        }
        return (int)dp[0];
    }
};
