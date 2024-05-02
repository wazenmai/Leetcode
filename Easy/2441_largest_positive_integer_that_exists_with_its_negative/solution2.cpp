/**
 * Title:  Largest Positive Integer That Exists With Its Negative (Leetcode Easy 2441)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, May, 2024
 */

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int st = 0, ed = nums.size() - 1;
        while (st != ed) {
            if (-nums[st] == nums[ed]) {
                return nums[ed];
            }
            if (-nums[st] >= nums[ed]) {
                st++;
            } else {
                ed--;
            }
        }
        return -1;
    }
};