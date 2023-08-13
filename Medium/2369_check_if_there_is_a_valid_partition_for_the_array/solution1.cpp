/**
 * Title:  Check If There Is A Valid Partition For The Array (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, August, 2023
 * Method: Bottom-Up Dp. dp[i] = true if nums[0:i] can be valid partitioned.
 */

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        for (int i = 1; i < n; i++) {
            if (i - 2 >= 0) {
                // check same
                if (nums[i - 2] == nums[i - 1] && nums[i - 1] == nums[i]) {
                    // cout << i << ": three same\n";
                    if (i - 3 >= 0 && dp[i] == false) {
                        dp[i] = dp[i - 3];
                    } else {
                        dp[i] = true;
                    }
                }
                // check increasing
                if (nums[i - 2] == nums[i - 1] - 1 && nums[i - 1] == nums[i] - 1) {
                    // cout << i << ": three increasing\n";
                    if (i - 3 >= 0 && dp[i] == false) {
                        dp[i] = dp[i - 3];
                    } else {
                        dp[i] = true;
                    }
                }
            }
            if (i - 1 >= 0) {
                if (nums[i - 1] == nums[i]) {
                    // cout << i << ": two same\n";
                    if (i - 2 >= 0 && dp[i] == false) {
                        dp[i] = dp[i - 2];
                    } else {
                        dp[i] = true;
                    }
                }
            }
        }
        return dp[n - 1];
    }
};
