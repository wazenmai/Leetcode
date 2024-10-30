/**
 * Title:  Minimum Number of Removals to Make Mountain Array (Leetcode Hard 1671)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, October, 2024
 * Method: First find the longest increasing subsequence from left to right and from right to left. Then iterate through all possible peaks and find the answer.
 * Result: Time complexity O(nlogn). Space complexity O(n).
 */


class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_lis, right_lis;
        vector<vector<int>> lis(n, vector<int>(2, 0));
        for (int i = 0; i < n; i++) {
            if (left_lis.empty() || nums[i] > left_lis.back()) {
                lis[i][0] = left_lis.size();
                left_lis.emplace_back(nums[i]);
            } else {
                auto it = lower_bound(left_lis.begin(), left_lis.end(), nums[i]); // the fitst position of val >= nums[i]
                lis[i][0] = it - left_lis.begin();
                *it = nums[i];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (right_lis.empty() || nums[i] > right_lis.back()) {
                lis[i][1] = right_lis.size();
                right_lis.emplace_back(nums[i]);
            } else {
                auto it = lower_bound(right_lis.begin(), right_lis.end(), nums[i]);
                lis[i][1] = it - right_lis.begin();
                *it = nums[i];
            }
        }
        int ans = n - 3;
        for (int i = 1; i < n - 1; i++) {
            if (lis[i][0] == 0 || lis[i][1] == 0) continue;
            ans = min(ans, n - (lis[i][0] + lis[i][1] + 1));
        }
        return ans;
    }
};