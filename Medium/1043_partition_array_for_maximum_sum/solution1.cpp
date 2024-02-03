/**
 * Title:  Partition Array for Maximum Sum (Leetcode Medium 1043)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, February, 2024
 * Method: dp[i] = maxSum(arr[0] ~ arr[i - 1]), dp[1] = arr[0]. dp[i] = dp[i - j] + max(arr[i - 1], ..., arr[i - j]) * j
 * Result: Time complexity O(n * k), space complexity O(n)
 */

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                if (j > i) break;
                int base = dp[i - j];
                int max_num = arr[i - 1];
                for (int k = 2; k <= j; k++) {
                    max_num = max(max_num, arr[i - k]);
                }
                dp[i] = max(dp[i], base + max_num * j);
            }
        }
        return dp[n];
    }
};
