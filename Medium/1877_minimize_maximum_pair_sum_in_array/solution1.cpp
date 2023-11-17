/**
 * Title:  Minimize Maximum Pair Sum in Array (Leetcode Medium 1877)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, November, 2023
 */

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n / 2; i++) {
            ans = max(ans, nums[i] + nums[n - 1 - i]);
        }
        return ans;
    }
};
