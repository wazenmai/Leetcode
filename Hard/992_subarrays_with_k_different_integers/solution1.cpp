/**
 * Title:  Subarrays with K Different Integers (Leetcode Hard 992)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, March, 2024
 * Method: Subarray with exact k distinct integers = subarray with at most k distinct integers - subarray with at most k - 1 distinct integers
 * Result: Time complexity is O(n), space complexity is O(n).
 */

class Solution {
public:
    int subarrayWithAtMostK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        unordered_map<int, int> m;
        int l = 0, ans = 0;
        int n = nums.size();
        for (int r = 0; r < n; r++) {
            m[nums[r]]++;
            // cout << nums[r] << ", " << m.size() << ", " << ans << "\n";
            while (m.size() > k && l < r) {
                if (m[nums[l]] == 1) {
                    m.erase(nums[l]);
                } else {
                    m[nums[l]]--;
                }
                l++;
            }
            ans += (r - l + 1);
        }
        // cout << "subarray with at most " << k << ", ans: " << ans << "\n";
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayWithAtMostK(nums, k) - subarrayWithAtMostK(nums, k - 1);
    }
};
