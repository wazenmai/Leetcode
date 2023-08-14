/**
 * Title:  Kth Largest Element In An Array (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, August, 2023
 * Method: Sorting. Time Complexity O(nlogn). Space Complexity O(1)
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k - 1];
    }
};
