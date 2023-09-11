/**
 * Title:  Longest Increasing Subsequence (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, Sep, 2023
 * Method: DP. O(N^2). state = dp[i] = len(LIS) of nums(i ~ n), every time we need to check (i + 1 ~ n) to find LIS of (i ~ n).
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        vector<int> dp(n, 1); // dp(i) = len(LIS) of nums(i~n)
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] < nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
