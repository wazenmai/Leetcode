/**
 * Title:  Search in Rotated Sorted Array (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, Mar, 2022
 * Method: Find the pivot then do binary search.
 */

class Solution {
public:
    bool binary_search(vector<int>& nums, int target, int pivot, int l, int r) {
        if (l >= r)
            return false;
        int mid = (l + r) / 2;
        int idx = (mid + pivot) % nums.size();
        // cout << "bs: (" << l << ", " << r << ") " << nums[idx] << "\n";
        if (target == nums[idx])
            return true;
        if (target > nums[idx])
            return binary_search(nums, target, pivot, mid + 1, r);
        return binary_search(nums, target, pivot, l, mid);
    }
    
    bool search(vector<int>& nums, int target) {
        int pivot = 0;
        int min_num = nums[0];
        int max_num = nums[0];
        int min_idx = 0, max_idx = 0;
        int n = (int)nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] < min_num) {
                min_num = nums[i];
                min_idx = i;
            }
            if (nums[i] > max_num && i < n - 1) {
                max_num = nums[i];
                max_idx = i + 1;
            }
        }
        pivot = (nums[max_idx] == nums[min_idx]) ? max_idx : min_idx;
        // cout << "pivot: " << pivot;
        return binary_search(nums, target, pivot, 0, n);
    }
};
