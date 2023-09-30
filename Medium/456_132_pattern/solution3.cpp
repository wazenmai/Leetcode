/**
 * Title:  132 Pattern (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, September, 2023
 * Result: O(N^2), TLE.
 */

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // better brute force: record min at left
        int min_i = 1e9;
        int n = nums.size();
        for (int j = 0; j < n - 1; j++) {
            min_i = min(min_i, nums[j]);
            for (int k = j + 1; k < n; k++) {
                if (nums[k] < nums[j] and min_i < nums[k]) {
                    return true;
                }
            }
        }
        return false;
    }
};
