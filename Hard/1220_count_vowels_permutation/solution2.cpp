/**
 * Title:  Count Vowels Permutation (Leetcode Hard 1220)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, October, 2023
 * Method: DP by iteration. dp[i][j] is the number of strings of length j that starts with the i-th vowel.
 * Result: Time Complexity O(n), Space Complexity O(n)
 */

class Solution {
public:
    int mod = 1e9 + 7;
    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));
        dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][4]) % mod;
            dp[i][3] = (dp[i - 1][2] + dp[i - 1][4]) % mod;
            dp[i][4] = dp[i - 1][0] % mod;
        }
        return int((dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4]) % mod);
    }
};

// ae
// ea / ei
// ia / ie / io / iu
// oi / ou
// ua