/**
 * Title:  Special Array With X Elements Greater Than or Equal X (Leetcode Easy 1608)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, May, 2024
 * Method: Binary Search
 * Result: Time complexity is O(nlogn). Space complexity is O(1).
 */

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // use binary search
        int l = 1, r = n + 1;
        while (l < r) {
            int mid = (l + r) / 2;
            int i;
            for (i = n - 1; i >= 0; i--) {
                if (nums[i] < mid)
                    break;
            }
            int cnt = n - 1 - i;
            if (cnt == mid) return mid;
            if (cnt > mid) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return -1;
    }
};
