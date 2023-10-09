/**
 * Title:  Find First and Last Position of Element in Sorted Array (Leetcode Medium 34)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   09, October, 2023
 * Method: Time complexity O(logn), Space complexity O(1)
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        int start = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                start = mid;
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (start == -1)
            return vector<int>{-1, -1};
        int end = -1;
        l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                end = mid;
                l = mid + 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return vector<int>{start, end};
    }
};
