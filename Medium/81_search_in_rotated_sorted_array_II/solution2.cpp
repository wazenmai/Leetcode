/**
 * Title:  Search in Rotated Sorted Array (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, Aug, 2023
 * Method: Find the pivot O(n) then do binary search O(logn).
 */

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // find pivot
        int n = nums.size();
        int pivot = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                pivot = i;
                break;
            }
        }
        
        // find target
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            int realMid = (mid + pivot) % n;
            if (nums[realMid] == target) {
                return true;
            } else if (nums[realMid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return false;
    }
};
