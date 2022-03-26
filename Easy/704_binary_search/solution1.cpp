/**
 * Title:  Binary Search (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, Mar, 2022
 */

class Solution {
public:
    int bs(vector<int>& nums, int target, int l, int r) {
        if (l >= r)
            return -1;
        int mid = (l + r) / 2;
        if (target == nums[mid])
            return mid;
        else if (target > nums[mid])
            return bs(nums, target, mid + 1, r);
        return bs(nums, target, 0, mid);
    }
    
    int search(vector<int>& nums, int target) {
        return bs(nums, target, 0, (int)nums.size());
    }
};
