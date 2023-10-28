/**
 * Title:  Count Vowels Permutation (Leetcode Hard 1220)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, October, 2023
 * Method: Top-down DP with memory optimization.
 * Result: Time Complexity O(n), Space Complexity O(1)
 */

class Solution {
public:
    int mod = 1e9 + 7;
    int countVowelPermutation(int n) {
        vector<long long> dp(5, 1);
        vector<long long> pre(5, 1);
        for (int i = 2; i <= n; i++) {
            dp[0] = pre[1] % mod;
            dp[1] = (pre[0] + pre[2]) % mod;
            dp[2] = (pre[0] + pre[1] + pre[3] + pre[4]) % mod;
            dp[3] = (pre[2] + pre[4]) % mod;
            dp[4] = pre[0] % mod;
            pre = dp;
        }
        return int((dp[0] + dp[1] + dp[2] + dp[3] + dp[4]) % mod);
    }
};

// ae
// ea / ei
// ia / ie / io / iu
// oi / ou
// ua