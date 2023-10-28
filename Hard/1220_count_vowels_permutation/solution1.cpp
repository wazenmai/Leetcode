/**
 * Title:  Count Vowels Permutation (Leetcode Hard 1220)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, October, 2023
 * Method: DP by recursion. dp[i][j] is the number of strings of length j that starts with the i-th vowel.
 * Result: Time Complexity O(n), Space Complexity O(n)
 */

class Solution {
public:
    int mod = 1e9 + 7;
    long long comb(char c, int n, vector<vector<long long>>& dp) {
        if (n == 1) return 1;
        if (c == 'a') {
            if (dp[0][n] != 0) return dp[0][n];
            return dp[0][n] = comb('e', n - 1, dp) % mod;
        } else if (c == 'e') {
            if (dp[1][n] != 0) return dp[1][n];
            return dp[1][n] = (comb('a', n - 1, dp) + comb('i', n - 1, dp)) % mod;
        } else if (c == 'i') {
            if (dp[2][n] != 0) return dp[2][n];
            return dp[2][n] = (comb('a', n - 1, dp) + comb('e', n - 1, dp) + comb('o', n - 1, dp) + comb('u', n - 1, dp)) % mod;
        } else if (c == 'o') {
            if (dp[3][n] != 0) return dp[3][n];
            return dp[3][n] = (comb('i', n - 1, dp) + comb('u', n - 1, dp)) % mod;
        } else if (c == 'u') {
            if (dp[4][n] != 0) return dp[4][n];
            return dp[4][n] = comb('a', n - 1, dp) % mod;
        }
        return 0;
    }
    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(5, vector<long long>(n + 1, 0));
        long long ans = comb('a', n, dp) + comb('e', n, dp) + comb('i', n, dp) + comb('o', n, dp) + comb('u', n, dp);
        return int(ans % mod);
    }
};

// ae
// ea / ei
// ia / ie / io / iu
// oi / ou
// ua