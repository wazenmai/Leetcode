/**
 * Title:  Minimum Size Subarray Sum (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, July, 2023
 * Method: Sliding window (two pointers)
 * Result: Accepted. Time Complexity O(n)
 */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = (int)nums.size();
        int sum = 0;
        int ans = INT_MAX;
        int left = 0;

        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum >= target) {
                sum -= nums[left];
                ans = min(ans, right - left + 1);
                ++left;
            }
        }

        if (ans == INT_MAX)
            return 0;
        return ans;
    }
};
