/**
 * Title:  Count Subarrays with Fixed Bounds (Leetcode Hard 2444)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, March, 2024
 * Method: Remove mincheck and maxcheck, use max(0, (min(min_pos, max_pos) - cutpoint)) to add the number of subarrays that satisfy the condition.
 * Result: Time complexity is O(n), space complexity is O(1).
 */

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int min_pos = -1, max_pos = -1;
        int cutpoint = -1;
        int n = nums.size();
        long long ans = 0;
        for (int r = 0; r < n; r++) {
            if (nums[r] < minK || nums[r] > maxK) { // cutpoint
                cutpoint = r;
                continue;
            }
            if (nums[r] == minK) {
                min_pos = r;
            }
            if (nums[r] == maxK) {
                max_pos = r;
            }
            ans += max(0, (min(min_pos, max_pos) - cutpoint));
            // cout << nums[r] << "(" << r << "), cut=" << cutpoint;
            // cout << ", min: " << min_pos;
            // cout << ", max: " << max_pos << "\n";
        }
        return ans;
    }
};
