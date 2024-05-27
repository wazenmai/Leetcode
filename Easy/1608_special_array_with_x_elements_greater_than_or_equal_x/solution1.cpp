/**
 * Title:  Special Array With X Elements Greater Than or Equal X (Leetcode Easy 1608)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, May, 2024
 * Method: Brute Force.
 * Result: Time complexity is O(n^2). Space complexity is O(1).
 */

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = -1;
        for (int x = 1; x <= n; x++) {
            if (nums[0] >= x && n == x) return x;
            for (int i = n - 1; i >= 0; i--) {
                if (nums[i] < x) {
                    if (n - 1 - i == x) {
                        return x;
                    }
                    break;
                }
            }
        }
        return ans;
    }
};
