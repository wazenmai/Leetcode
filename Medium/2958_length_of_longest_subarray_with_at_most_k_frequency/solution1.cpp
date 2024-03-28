/**
 * Title:  Length of Longest Subarray With at Most K Frequency (Leetcode Medium 2958)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, March, 2024
 * Result: Time complexity O(n), Space complexity O(n).
 */

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int ans = 0, len = 0, l = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) { // right
            m[nums[i]]++;
            while (m[nums[i]] > k) {
                m[nums[l]]--;
                l++;
                len--;
            }
            len++;
            ans = max(ans, len);
        }
        return ans;
    }
};
