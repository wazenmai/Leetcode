/**
 * Title:  Minimum Number of Taps to Open to Water a Garden (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, August, 2023
 * Method: DP. dp[i] = minTaps to water (0~i). Every time iterate ranges(i) to update dp. Time complexity O(n^2)
 */

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n + 1, 100000); // dp[i] = minTaps to water (0~i)
        dp[0] = 0;
        for (int i = 0; i <= n; i++) {
            int l = max(0, i - ranges[i]);
            int r = min(n, i + ranges[i]);
            for (int j = l; j <= r; j++) {
                dp[r] = min(dp[r], dp[j] + 1);
            }
        }
        if (dp[n] == 100000)
            return -1;
        return dp[n];
    }
};
