/**
 * Title:  Binary Subarrays With Sum (Leetcode Medium 930)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, March, 2024
 * Method: Sliding window. When s == goal, count the number of zeros before and after the current window, ans += (zeros_before + 1) * (zeros_after + 1). Update the number and the window.
 *        If goal == 0, use zeroGoal function to solve it.
 * Result: Time complexity O(n), Space complexity O(1).
 */

class Solution {
public:
    int zeroGoal(vector<int>& nums) {
        int zeros = 0;
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeros++;
                ans += zeros;
            } else {
                zeros = 0;
            }
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if (goal == 0) return zeroGoal(nums);
        int ans = 0;
        int s = nums[0]; // temp sum
        int n = nums.size();
        int l = 0, r = 1; // [l, r)
        while (l < n) {
            // cout << "(" << l << "," << r << "): " << s << ", " << ans << "\n";
            if (s == goal) {
                // Count zero_before and zero_after
                int zeros_before = 0;
                while (nums[l] == 0) {
                    zeros_before++;
                    l++;
                }
                int zeros_after = 0;
                while (r < n && nums[r] == 0) {
                    zeros_after++;
                    r++;
                }
                ans += (zeros_before + 1) * (zeros_after + 1);
                // Update number
                s -= nums[l];
                l++;
            } else if (s < goal) { // r++
                if (r < n) {
                    s += nums[r];
                    r++;
                } else {
                    break;
                }
            } else { // s > goal
                break;
            }
        }
        return ans;
    }
};

// 1 0 1 0 1

// 0 0 0 1 0 0 0 1 0 0 0, goal: 1

// 0 1 0