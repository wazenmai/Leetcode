/**
 * Title:  Maximum Sum of 3 Non-Overlapping Subarrays (Leetcode Hard 689)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, December, 2024
 * Method: Bottom-Up DP.
 * Result: Time complexity O(n). Space complexity O(n). n is the size of the input array.
 */

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> subarray(n - k + 1);
        int s = 0;
        for (int i = 0; i < k; i++) {
            s += nums[i];
        }
        subarray[0] = s;
        for (int i = k; i < n; i++) {
            s -= nums[i - k];
            s += nums[i];
            subarray[i - k + 1] = s;
        }
        vector<vector<vector<int>>> dp(n - k + 1, vector<vector<int>>(3, vector<int>(4, 0)));
        int max_sum = 0;
        int max_id = 0;
        for (int i = 0; i <= n - k; i++) {
            // take 1 subarray
            if (i - 1 < 0 || subarray[i] > dp[i - 1][0][0]) {
                dp[i][0][0] = subarray[i];
                dp[i][0][1] = i;
            } else {
                dp[i][0] = dp[i - 1][0];
            }
            // take 2 subarray
            if (i - k >= 0 && dp[i - k][0][0] + subarray[i] > dp[i - 1][1][0]) {
                dp[i][1][0] = dp[i - k][0][0] + subarray[i];
                dp[i][1][1] = dp[i - k][0][1];
                dp[i][1][2] = i;
            } else if (i - 1 >= 0) {
                dp[i][1] = dp[i - 1][1];
            }
            // take 3 subarray
             if (i - k >= 0 && dp[i - k][1][0] + subarray[i] > dp[i - 1][2][0]) {
                dp[i][2][0] = dp[i - k][1][0] + subarray[i];
                dp[i][2][1] = dp[i - k][1][1];
                dp[i][2][2] = dp[i - k][1][2];
                dp[i][2][3] = i;
            } else if (i - 1 >= 0) {
                dp[i][2] = dp[i - 1][2];
            }
            if (dp[i][2][0] > max_sum) {
                max_id = i;
                max_sum = dp[i][2][0];
            }
        }
        vector<int> ans;
        for (int i = 1; i < 4; i++) {
            ans.emplace_back(dp[max_id][2][i]);
        }
        return ans;
    }
};
// dp[i][j][0] = after seeing subarray 0 - i, take subarray i and now have j + 1 continuous array in the pocket
// dp[i][j][1,2,3] = the index of subarray

// Optimization from O(n^2) to O(n)
// dp[i][j][0] = after seeing subarray 0 - i and now have j + 1 continuous array in the pocket
// dp[i][j][1,2,3] = the index of subarray
