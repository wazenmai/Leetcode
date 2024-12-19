/**
 * Title:  Partition Equal Subset Sum (Leetcode Medium 416)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, December, 2024
 * Method: Recursion with memorization. dp[i][j] represents whether the state with choosing the first i numbers that sum to j is possible to get the answer.
 * Result: Time complexity O(n*goal), Space complexity O(n*goal).
 */

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int goal = sum / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(goal, -1));

        function<bool(int, int)> helper = [&](int id, int sum) {
            if (sum == goal) return true;
            if (id >= n || sum > goal) return false;
            if (dp[id][sum] != -1) return dp[id][sum] == 1;
            if (helper(id + 1, sum + nums[id])) {
                dp[id][sum] = 1;
                return true;
            }
            dp[id][sum] = (helper(id + 1, sum)) ? 1 : 0;
            return dp[id][sum] == 1;
        };

        return helper(0, 0);
    }
};
