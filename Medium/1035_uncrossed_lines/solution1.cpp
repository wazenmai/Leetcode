/**
 * Title:  Uncrossed Lines (Leetcode Medium 1035)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, November, 2024
 * Method: LCS. dp[i][j] = maximum length of uncrossed lines between nums1[0:i] and nums2[0:j].
 * Result: Time complexity O(nm). Space complexity O(nm), where n = nums1.size(), m = nums2.size().
 */


class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums1[i] == nums2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[n][m];
    }
};
