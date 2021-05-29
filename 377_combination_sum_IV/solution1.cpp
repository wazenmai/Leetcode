/**
 * Title:  Combination Sum IV (Leetcode Medium 377)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   3, May, 2021
 */

class Solution {
private:
    int dp[1010];
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= target; i++)
            dp[i] = 0;
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (auto& n : nums) {
                if (n > i)
                    break;
                dp[i] += dp[i - n];
                cout << "target = " << i << ", += dp[" << i - n << "] -> " << dp[i] << "\n";
            }
        }
        return dp[target];
    }
};
