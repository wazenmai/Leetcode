/**
 * Title:  Maximum Product Subarray (Leetcode Medium 152)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   3, May, 2021
 */

/**
 * Dynamic Programming
 * dp[i][1]: largest product when end index = i
 * dp[i][2]: smallest product when end index = i
 * dp[i][1] = max(nums[i], max(nums[i] * dp[i-1][1], nums[i] * dp[i-1][2]))
 * dp[i][2] = min(nums[i], min(nums[i] * dp[i-1][1], nums[i] * dp[i-1][2]))
 */

class Solution {
private:
    int dp[20010][2];
public:
    int maxProduct(vector<int>& nums) {
        int length = nums.size();
        if (length == 1)
            return nums[0];

        for (int i = 0; i < length; i++) {
            if (i == 0) {
                dp[i][0] = dp[i][1] = nums[i];
            } else {
                dp[i][0] = max(nums[i], max(nums[i] * dp[i-1][0], nums[i] * dp[i-1][1]));
                dp[i][1] = min(nums[i], min(nums[i] * dp[i-1][0], nums[i] * dp[i-1][1]));
            }
        }
        int ans = -1e9;
        for (int i = 0; i < length; i++) {
            if (dp[i][0] > ans)
                ans = dp[i][0];
        }
        return (int)ans;
    }
};
