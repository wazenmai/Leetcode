/**
 * Title:  132 Pattern (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, September, 2023
 * Method: Find the maximum interval (i, j) and then find k that suit 132 pattern.
 * Result: O(N^2) = O(N * N / 2), TLE.
 */

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // find the endpoints of a local rising slope
        int n = nums.size();
        vector<pair<int, int>> intervals;
        int min_point_after_last_peak_index = 0;
        for (int i = 1; i < n; i++) {
            // If we encounter a falling edge, then i - 1 is a peak
            if (nums[i] < nums[i - 1]) {
                // Make sure that peak occurs after the rising edge's minimum
                if (min_point_after_last_peak_index < i - 1) {
                    // nums[i - 1] is a valid rising peak
                    intervals.push_back({nums[min_point_after_last_peak_index], nums[i - 1]});
                }
                // The current element is the minimum for the next rising peak
                min_point_after_last_peak_index = i;
            }
            for (auto interval: intervals) {
                if (nums[i] > interval.first and nums[i] < interval.second)
                    return true;
            }
        }
        return false;
    }
};
