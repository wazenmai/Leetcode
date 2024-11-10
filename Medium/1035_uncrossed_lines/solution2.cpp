/**
 * Title:  Uncrossed Lines (Leetcode Medium 1035)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, November, 2024
 * Method: Memory optimization.
 * Result: Time complexity O(nm). Space complexity O(m), where n = nums1.size(), m = nums2.size().
 */

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> dp(m + 1, 0);
        vector<int> pre = dp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums1[i] == nums2[j]) {
                    dp[j + 1] = pre[j] + 1;
                } else {
                    dp[j + 1] = max(dp[j], pre[j + 1]);
                }
            }
            pre = dp;
        }
        return pre[m];
    }
};
