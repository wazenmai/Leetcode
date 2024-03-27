/**
 * Title:  Subarray Product Less Than K (Leetcode Medium 713)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, March, 2024
 * Result: Time complexity O(n^2), Space complexity O(1).
 */

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            long long p = nums[i];
            if (p < k) ans++;
            for (int j = i + 1; j < n; j++) {
                p *= nums[j];
                if (p < k) ans++;
                if (p >= k) break;
            }
        }
        return ans;
    }
};
