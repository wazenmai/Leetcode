/**
 * Title:  Minimum Swaps to Group All 1's Together II (Leetcode Medium 2134)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, August, 2024
 * Method: The length of the group of 1 is the number of 1's. We can use a sliding window and iterate the starting point from 0 to n-1 to check the number of 0's in the window. The answer is the minimum number of 0's in the window.
 * Result: Time complexity is O(n), space complexity is O(1).
 */

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                ones++;
        }
        int zeros = 0;
        for (int i = 0; i < ones; i++) {
            if (nums[i] == 0)
                zeros++;
        }
        int ans = zeros;
        for (int i = 1; i < n; i++) { // start point
            int pos = (i + ones - 1) % n;
            if (nums[i - 1] == 0) zeros--;
            if (nums[pos] == 0) zeros++;
            ans = min(zeros, ans);
        }        
        return ans;
    }
};
// 0 1 2 3 4 5 6
// 1 0 1 0 1 0 1, z = 2
// 0 1 0 1 0 1 0
