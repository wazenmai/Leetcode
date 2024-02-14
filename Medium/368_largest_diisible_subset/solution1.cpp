/**
 * Title:  Largest Divisible Subset (Leetcode Medium 368)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   09, February, 2024
 * Method: DP. Simlar to LIS. Sort the array first. Then use dp[i] to store the maximum number of numbers in divisible subset including i. Use pre[i] to store the previous index of i in the subset.
 * Result: Time complexity O(n^2), space complexity O(n).
 */

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> pre(n, -1);
        int ans = 0;
        int id = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    }
                }
            }
            if (dp[i] > ans) {
                ans = dp[i];
                id = i;
                // cout << "number (" << i << "," << nums[i] << "): " << dp[i] << ", " << pre[i] << "\n";
            }
        }
        vector<int> res;
        while (id != -1) {
            res.emplace_back(nums[id]);
            id = pre[id];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// dp[i] = the maximum number of numbers in divisible subset including i
