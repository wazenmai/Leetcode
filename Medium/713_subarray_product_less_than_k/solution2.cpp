/**
 * Title:  Subarray Product Less Than K (Leetcode Medium 713)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, March, 2024
 * Method: Use two pointers to find the subarray that has product less than k. The product of subarray [l, r] is p = nums[l] * nums[l + 1] * ... * nums[r]. If p >= k, move l to right until p < k. The number of subarrays that end at r is r - l + 1.
 * Result: Time complexity O(n), Space complexity O(1).
 */

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        long long p = 1;
        int l = 0;
        for (int r = 0; r < n; r++) {
            p *= nums[r];
            while (l <= r && p >= k) {
                p /= nums[l];
                l++;
            }
            ans += (r - l + 1);
        }
        return ans;
    }
};
// [10,5,2,6]
// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
