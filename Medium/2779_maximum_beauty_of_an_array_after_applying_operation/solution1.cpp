/**
 * Title:  Maximum Beauty of an Array After Applying Operation (Leetcode Medium 2779)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, December, 2024
 * Method: Sliding window. Sort the array first and find the maximum right end of the window.
 * Result: Time complexity is O(nlogn), space complexity is O(1).
 */

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int r = 0;
        int ans = 0;
        for (int l = 0; l < n; l++) {
            while (r < n && nums[l] + k >= nums[r] - k) {
                r++;
            }
            // cout << "(" << l << "," << r << "): " << nums[l] << "\n";
            ans = max(ans, r - l);
        }
        return ans;
    }
};
// 1246
