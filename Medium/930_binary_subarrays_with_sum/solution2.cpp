/**
 * Title:  Binary Subarrays With Sum (Leetcode Medium 930)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, March, 2024
 * Method: Prefix sum. Use a map to store the prefix sum and its frequency. When the prefix sum is equal to goal, ans++. If the prefix sum - goal is in the map, ans += m[prefix_sum - goal].
 * Result: Time complexity O(n), Space complexity O(n).
 */

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> m;
        int n = nums.size();
        int ans = 0;
        int s = 0;
        for (int i = 0; i < n; i++) {
            s += nums[i];
            if (s == goal) {
                ans++;
            }
            if (m.find(s - goal) != m.end()) {
                ans += m[s - goal];
            }
            m[s]++;
        }
        return ans;
    }
};
