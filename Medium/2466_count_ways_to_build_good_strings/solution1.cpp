/**
 * Title:  Count Ways To Build Good Strings (Leetcode Medium 2466)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, December, 2024
 * Method: DP. dp[i][j] = # of ways to construct string of length i and end at 0/1. dp[i][0] = dp[i - zero][0] + dp[i - zero][1], dp[i][1] = dp[i - one][0] + dp[i - one][1]. Then iterate from low to high to get the answer.
 * Result: Time complexity is O(high), space complexity is O(high).
 */

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<vector<long long>> dp(high + 1, vector<long long>(2, 0));
        dp[0][0] = dp[0][1] = 1;
        long long ans = 0;
        int mod = 1e9 + 7;
        for (int i = 1; i <= high; i++) {
            if (i >= zero) {
                if (i - zero == 0) {
                    dp[i][0] = 1;
                } else {
                    dp[i][0] = (dp[i - zero][0] + dp[i - zero][1]) % mod;
                }
            }
            if (i >= one) {
                if (i - one == 0) {
                    dp[i][1] = 1;
                } else {
                    dp[i][1] = (dp[i - one][0] + dp[i - one][1]) % mod;
                }
            }
            // cout << i << ": " << dp[i][0] << " " << dp[i][1] << "\n";
            if (i >= low) {
                ans += (dp[i][0] + dp[i][1]);
                ans %= mod;
            }
        }
        return (int)ans;
    }
};

// dp[i][j] = # of ways to construct string of length i and end at 0/1
// [2, 3], zero = 1, one = 2

// dp[0][0] = 1, dp[0][1] = 1
// dp[1][0] = 1, ('0'), dp[1][1] = 0 ('1')
// dp[2][0] = 1, dp[2][1] = 1 -> 00, 11 = 2
// dp[3][0] = 2, dp[3][1] = 1 -> 
// 