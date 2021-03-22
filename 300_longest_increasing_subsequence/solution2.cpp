/**
 * Title:  Longest Increasing Subsequence (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, Mar, 2021
 */

// dp

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int size = nums.size();
        int ans = 0;

        for (int i = size - 1; i >= 0; i--) {
            for (int j = size - 1; j > i; j--) {
                if (nums[j] > nums[i]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
