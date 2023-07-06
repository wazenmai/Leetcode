/**
 * Title:  Minimum Size Subarray Sum (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, July, 2023
 * Method: Binary search the window size. Inside the window, find maximum size when window size = mid.
 * Result: Accepted. Time Complexity O(nlogn)
 */

 class Solution {
public:
    bool findWindow(int size, vector<int>& nums, int target) {
        int n = (int)nums.size();
        int sum = 0;
        int ws = 0; // sum in the window
        int left = 0;
        int right = 0;

        while(right < n) {
            sum += nums[right];
            if (right - left + 1 == size) {
                ws = max(sum, ws);
                sum -= nums[left];
                ++left;
            }
            ++right;
        }

        if (ws >= target)
            return true;
        return false;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        // binary search
        int low = 1;
        int high = (int)nums.size();
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (findWindow(mid, nums, target)) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
