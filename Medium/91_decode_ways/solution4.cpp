/**
 * Title:  Decode Ways (Leetcode Medium 91)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, December, 2024
 * Method: Memory Optimization since we only use dp[i - 1] and dp[i - 2] to construct current value.
 * Result: Time complexity O(n), space complexity O(1)
 */

class Solution {
public:
    int numDecodings(const string& s) {
        int n = s.length();
        if (s[0] == '0') return 0;
        int cur = 1;
        int pre1 = 1; // dp[i - 1]
        int pre2 = 1; // dp[i - 2]
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                cur = (s[i] == '0') ? pre2 : pre1 + pre2;
            } else if (s[i] == '0') {
                return 0;
            } else {
                cur = pre1;
            }
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};

// dp[i] = # of ways to decode s(0~i)
