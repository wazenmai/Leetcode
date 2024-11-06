/**
 * Title:  Longest Arithmetic Subsequence (Leetcode Medium 1027)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, November, 2024
 * Method: dp[i][j] = the length of longest arithmetic subsequence ends at i with difference j (+offset 500). Concstruct a dp array with size range(nums[i]) * range(nums[i] - nums[j]) = 501 * 1002.
 *         For each number, check all possible difference from -500 to 500, if existed arithmetic subsequence, update dp[i][j] = dp[i - j][j] + 1, otherwise, check previous number by dp[i - j][0].
 * Result: Time complexity is O(n^2), space complexity is O(n^2).
 */

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        // dp[i][j] = the length of longest arithmetic subsequence ends at i with difference j
        vector<vector<int>> dp(501, vector<int>(1002, -1)); // range(nums[i]), range(nums[i] - nums[j]) = -500 ~ 500
        int n = nums.size();
        dp[nums[0]][0] = 1;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            for (int j = nums[i] - 500; j <= nums[i]; j++) {
                int col = j + 500; // add offset
                if (dp[nums[i] - j][col] > 0) { // existed arithmetic subsequence
                    dp[nums[i]][col] = max(dp[nums[i]][col], dp[nums[i] - j][col] + 1);
                } else { // check previous number by dp[nums[i] - j][0]
                    dp[nums[i]][col] = max(dp[nums[i]][col], dp[nums[i] - j][0] + 1);
                }
                ans = max(ans, dp[nums[i]][col]);
            }
            dp[nums[i]][0] = max(dp[nums[i]][0], 1);
        }
        return ans;
    }
};
