/**
 * Title:  Minimum Number of Removals to Make Mountain Array (Leetcode Hard 1671)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, October, 2024
 * Method: For each possible peak, compute the left longest increasing subsequence and right longest decreasing subsequence. The answer is n - max_left - max_right - 1.
 *         The method for finding LIS is using a dp array, dp[i] = length of LIS ending with nums[i]. For each position i, iterate through all previous position j < i and find the maximum length.
 * Result: TLE. Time complexity O(n^3). Space complexity O(n).
 */

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        int ans = n - 3;
        for (int i = 1; i < n - 1; i++) { // peak
            // left side
            int max_left = 0;
            vector<int> dp(i, 0);
            for (int j = 0; j < i; j++) {
                if (nums[j] >= nums[i]) continue;
                dp[j] = 1;
                for (int k = 0; k < j; k++) {
                    if (nums[k] < nums[j]) {
                        dp[j] = max(dp[j], dp[k] + 1);
                    }
                }
                max_left = max(max_left, dp[j]);
            }
            if (max_left == 0) continue;
            // right side
            int max_right = 0;
            vector<int> dp2(n - i - 1, 0);
            for (int j = i + 1; j < n; j++) {
                if (nums[j] >= nums[i]) continue;
                dp2[j - i - 1] = 1;
                for (int k = i + 1; k < j; k++) {
                    if (nums[k] > nums[j]) {
                        dp2[j - i - 1] = max(dp2[j - i - 1], dp2[k - i - 1] + 1);
                    }
                }
                max_right = max(max_right, dp2[j - i - 1]);
            }
            if (max_right == 0) continue;
            // cout << "center (" << i << "): " << nums[i] << ", " << n - max_left - max_right - 1 << "\n";
            ans = min(ans, n - max_left - max_right - 1);
        }
        return ans;
    }
};
