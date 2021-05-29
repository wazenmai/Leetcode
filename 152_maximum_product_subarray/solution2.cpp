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
public:
    int maxProduct(vector<int>& nums) {
        int length = nums.size();
        int dp_0, dp_1, temp_0, temp_1;
        int ans = -1e9;

        if (length == 1)
            return nums[0];

        dp_0 = dp_1 = nums[0];
        ans = max(ans, dp_0);
        for (int i = 1; i < length; i++) {
            temp_0 = max(nums[i], max(nums[i] * dp_0, nums[i] * dp_1));
            temp_1 = min(nums[i], min(nums[i] * dp_0, nums[i] * dp_1));
            ans = max(ans, temp_0);
            dp_0 = temp_0;
            dp_1 = temp_1;
        }
        return ans;
    }
};
