/**
 * Title:  House Robber (Leetcode Medium 198)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   3, May, 2021
 */

/**
 * Dynamic Programming
 * dp[i] = maximum money with stealing house i
 * dp[i] = (dp[i-2], dp[i-3], 0) + nums[i]
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        int turn = 0, ans = -1;
        int dp[4];
        dp[0] = dp[1] = dp[2] = dp[3] = -1;
        
        if (length == 1) {
            return nums[0];
        } else if (length == 2) {
            return max(nums[0], nums[1]);
        }

        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[2] + dp[0];
        ans = max(dp[2], dp[1]);
        turn = 3;
        for (int i = 3; i < length; i++) {
            if (turn == 0) {
                dp[0] = max(dp[1], dp[2]) + nums[i];
            } else if (turn == 1) {
                dp[1] = max(dp[2], dp[3]) + nums[i];
            } else if (turn == 2) {
                dp[2] = max(dp[0], dp[3]) + nums[i];
            } else {
                dp[3] = max(dp[1], dp[0]) + nums[i];
            }
            ans = max(dp[turn], ans);
            turn = (turn + 1) % 4;
        }
        return ans;
    }
};
