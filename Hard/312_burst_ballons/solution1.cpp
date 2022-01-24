/**
 * Title:  Burst Ballons (Leetcode Hard 312)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, Jan, 2022
 * Method: dp[i][j] = the maximum money I can get between [i+1, j-1]
 * Result: Accepted
 */

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);
        int n = nums.size();

        int dp[502][502] = {0};
            
        for (int i = n-1; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                for (int k = i+1; k <= j-1; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[j] * nums[k]);
                    // cout << "dp(" << i << ", " << j << "): " << dp[i][j] << "\n";
                }
            }
        }
        return dp[0][n-1];
    }
};
