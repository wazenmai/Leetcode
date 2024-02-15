/**
 * Title:  Find Polygon With the Largest Perimeter (Leetcode Medium 2971)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, February, 2024
 * Method: Sort the array first. Then use prefix_sum[i] to store the sum of the first i numbers. Then traverse the array from the end to find the largest perimeter.
 * Result: Time complexity O(nlogn), space complexity O(n).
 */

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefix_sum(n, 0);
        prefix_sum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = nums[i] + prefix_sum[i - 1];
        }
        for (int i = n - 1; i >= 2; i--) {
            if (nums[i] < prefix_sum[i - 1]) return prefix_sum[i];
        }
        return -1;
    }
};
