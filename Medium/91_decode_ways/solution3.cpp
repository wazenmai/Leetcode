/**
 * Title:  Decode Ways (Leetcode Medium 91)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, December, 2024
 * Method: DP. dp[i] = # of ways to decode s(0 ~ i).
 * Result: Time complexity O(n), space complexity O(1)
 */

class Solution {
public:
    int numDecodings(const string& s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        if (s[0] == '0') return 0;
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                if (s[i] == '0') {
                    dp[i + 1] = dp[i - 1];
                } else {
                    dp[i + 1] = dp[i] + dp[i - 1];
                }
            } else if (s[i] == '0') {
                return 0;
            } else {
                dp[i + 1] = dp[i];
            }
            // cout << "dp[" << i + 1 << "]=" << dp[i + 1] << "\n";
        }
        return dp[n];
    }
};

// dp[i] = # of ways to decode s(0~i)