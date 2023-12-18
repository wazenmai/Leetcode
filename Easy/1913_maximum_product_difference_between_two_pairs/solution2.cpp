/**
 * Title:  Maximum Product Difference Between Two Pairs (Leetcode Easy 1913)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, December, 2023
 * Result: Time complexity O(NlogN)
 */

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n - 1] * nums[n - 2] - nums[0] * nums[1];
    }
};
