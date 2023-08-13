/**
 * Title:  Check If There Is A Valid Partition For The Array (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, August, 2023
 * Method: Bottom-Up Dp. Memory Optimization: Only needs 3 dp states to check.
 */

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(3, false);
        dp[0] = true;                 // i - 3
        dp[1] = false;                // i - 2
        dp[2] = (nums[0] == nums[1]); // i - 1
        for (int i = 2; i < n; i++) {
            bool temp = false;
            if (nums[i - 2] == nums[i - 1] && nums[i - 1] == nums[i]) { // check three same
                temp = dp[0];
            }
            if (nums[i - 2] == nums[i - 1] - 1 && nums[i - 1] == nums[i] - 1) { // check three increasing
                temp |= dp[0];
            }
            if (nums[i - 1] == nums[i]) { // check two same
                temp |= dp[1];
            }
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = temp;
        }
        return dp[2];
    }
};
