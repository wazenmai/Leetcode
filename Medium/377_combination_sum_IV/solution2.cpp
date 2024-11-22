/**
 * Title:  Combination Sum IV (Leetcode Medium 377)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   377, November, 2024
 * Method: Please see the explanation below.
 * Result: Time complexity O(n * target), Space complexity O(target).
 */

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (target < nums[0]) return 0;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = nums[0]; i <= target; i++) { // iterate through numbers
            for (int& num: nums) {
                if (num > i) break;
                dp[i] += dp[i - num]; // take num as first one, the combinations of i - num
            }
        }
        return dp[target];
    }
};

// dp[i] = number of permutations that sum to i using all nums
// dp[i] += dp[i - j] for j in nums

// Below is wrong state
// dp[i][j] = # of permutations that sum to i using nums[0 - j]
// dp[i][j] = dp[i][j - 1] + dp[i - nums[j]][j]
// If we iterate the loop from i = nums[0] ~ target, j = 0 ~ n, we can calculate dp[i][j - 1] before meeting dp[i][j], and simply add on it.
// This is wrong because dp[i - nums[j]][j] did not consider the case that nums[j] isn't the first number in permutation.
// Take below example, dp[4][2] += dp[4 - nums[2]][2] = dp[1][2], it only consider (3, 1) but not (1, 3).


// nums = [1,2,3], target = 4
// i = 1 ~ 4
// dp[1] += dp[0] = 1
// i = 2
// dp[2] += dp[1] = 1, += dp[0] = 2
// i = 3
// dp[3] += dp[2] = 2, += dp[1] = 1 += dp[0] = 1 = 4
// i = 4
// dp[4] += dp[3] = 4, dp[2] = 2, dp[1] = 1
