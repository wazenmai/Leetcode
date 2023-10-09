/**
 * Title:  Find First and Last Position of Element in Sorted Array (Leetcode Medium 34)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   09, October, 2023
 * Method: Time complexity O(n), Space complexity O(1)
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = -1, end = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == target && start == -1) {
                start = i;
            } else if (nums[i] > target && end == -1) {
                end = i - 1;
            }
        }
        if (start == -1)
            return vector<int>{-1, -1};
        if (end == -1)
            return vector<int>{start, n - 1};
        return vector<int>{start, end};
    }
};
