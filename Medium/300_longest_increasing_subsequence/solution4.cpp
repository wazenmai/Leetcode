/**
 * Title:  Longest Increasing Subsequence (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, Sep, 2023
 * Method: O(nlogn). Use vector `sub` to record the LIS, if x is smaller than the last element, then we replace the array with smaller number.
 *         lower_bound: binary search array to find the first element >= x
 */

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int x: nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.emplace_back(x);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), x); // find the index of the first element >= x
                *it = x;
            }
        }
        return sub.size();
    }
};
