/**
 * Title:  Max Dot Product of Two Subsequences (Leetcode Hard 1458)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, October, 2023
 * Method: Bottom-up DP with memory optimization, using concept of LCS.
 * Result: Time complexity O(n * m), Space complexity O(m)
 */

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // find max and min
        int max1 = -1000, max2 = -1000;
        int min1 = 1000, min2 = 1000;
        for (int& num: nums1) {
            max1 = max(max1, num);
            min1 = min(min1, num);
        }
        for (int& num: nums2) {
            max2 = max(max2, num);
            min2 = min(min2, num);
        }
        if (max1 < 0 && min2 > 0) return max1 * min2;
        if (min1 > 0 && max2 < 0) return min1 * max2;

        int n = nums1.size();
        int m = nums2.size();
        vector<int> dp(m + 1, 0);
        vector<int> prev(m + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                dp[j] = max(nums1[i] * nums2[j] + prev[j+1], max(prev[j], dp[j+1]));
            }
            prev = dp;
        }
        return dp[0];
    }
};

// dp[i][j]: max dot product of subsequence start from nums1[i] and nums2[j]
// dp[0][0] is answer
// dp[3][2] = -30
// nums1(i ... n - 1)
// nums2(j ... m - 1)
// 1. nums1[i] * nums2[j] + dp[i+1][j+1]
// 2. skip nums1[i] -> dp[i+1][j]



