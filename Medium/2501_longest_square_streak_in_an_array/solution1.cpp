/**
 * Title:  Longest Square Streak in an Array (Leetcode Medium 2501)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, October, 2024
 * Method: Brute force.
 * Result: Time complexity O(n). Space complexity O(n).
 */

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int max_num = 330;
        unordered_set us(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (nums[i] >= max_num) continue;
            int temp = 1;
            int num = nums[i];
            while (num < max_num && us.find(num * num) != us.end()) {
                temp++;
                num = num * num;
            }
            ans = max(temp, ans);
        }
        return (ans < 2) ? -1 : ans;
    }
};
