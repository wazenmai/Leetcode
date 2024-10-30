/**
 * Title:  Minimum Number of Removals to Make Mountain Array (Leetcode Hard 1671)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, October, 2024
 * Method: Use O(nlogn) to find LIS intead of O(n^2). We maintain a vector for longest increasing subsequence. If we met number < last element, we use binary search to find the first element > number and replace it.
 * Result: Time complexity O(n^2logn). Space complexity O(n).
 */

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        int ans = n - 3;
        for (int i = 1; i < n - 1; i++) { // peak
            // left side
            vector<int> left;
            for (int j = 0; j < i; j++) {
                if (nums[j] >= nums[i]) continue;
                if (left.size() == 0 || nums[j] > left.back()) {
                    left.emplace_back(nums[j]);
                } else {
                    auto it = lower_bound(left.begin(), left.end(), nums[j]);
                    *it = nums[j];
                }
            }
            if (left.empty()) continue;
            // right side
            vector<int> right;
            for (int j = n - 1; j > i; j--) {
                if (nums[j] >= nums[i]) continue;
                if (right.size() == 0 || nums[j] > right.back()) {
                    right.emplace_back(nums[j]);
                } else {
                    auto it = lower_bound(right.begin(), right.end(), nums[j]);
                    *it = nums[j];
                }
            }
            if (right.empty()) continue;
            ans = min(ans, n - (int)left.size() - (int)right.size() - 1);
        }
        return ans;
    }
};
