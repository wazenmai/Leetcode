/**
 * Title:  Kth Largest Element In An Array (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, August, 2023
 * Method: Quick Select. First choose a random pivot and split the number to left, mid, right group. Time Complexity O(n) on average. O(n^2) in worst case. Space Complexity O(n)
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int pivot = nums[rand() % nums.size()];

        vector<int> left;
        vector<int> mid;
        vector<int> right;

        for (int num: nums) {
            if (num < pivot)
                left.emplace_back(num);
            else if (num > pivot)
                right.emplace_back(num);
            else
                mid.emplace_back(num);
        }

        if (k <= right.size()) {
            return findKthLargest(right, k);
        }
        if (right.size() + mid.size() < k) {
            return findKthLargest(left, k - right.size() - mid.size());
        }
        return pivot;
    }
};
