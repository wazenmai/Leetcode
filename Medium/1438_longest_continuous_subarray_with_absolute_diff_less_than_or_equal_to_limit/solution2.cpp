/**
 * Title:  Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit (Leetcode Medium 1438)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, June, 2024
 * Method: Use deque to store the maximum and minimum values' indexes in the current window. In every step, we move r to right, if the condition is not satisfied, we move l to right.
 * Result: Time complexity is O(n), space complexity is O(n).
 */

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int l = 0, r = 0, ans = 0;
        deque<int> maxi; // number from large to small, record index
        deque<int> mini; // number from small to large, record index
        while (r < n) {
            while (!maxi.empty() && nums[maxi.back()] < nums[r]) maxi.pop_back();
            while (!mini.empty() && nums[mini.back()] > nums[r]) mini.pop_back();
            maxi.push_back(r);
            mini.push_back(r);
            while (nums[maxi.front()] - nums[mini.front()] > limit) {
                l++;
                while (maxi.front() < l) maxi.pop_front();
                while (mini.front() < l) mini.pop_front();
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
