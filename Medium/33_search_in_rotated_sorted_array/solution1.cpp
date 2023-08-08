/**
 * Title:  Search In Rotated Sorted Array (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, August, 2023
 * Method: Two binary search. First find the pivot, then find the target. Time complexity: O(logn), Space complexity: O(1)
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // find pivot
        int n = nums.size();
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[n - 1]) { // pivot at right
                l = mid + 1;
            } else { // pivot at left
                r = mid;
            }
        }
        int pivot = l;
        // find target
        l = 0;
        r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            int real = (mid + pivot) % n; // fix the position with pivot
            if (nums[real] == target)
                return real;
            if (nums[real] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};
