/**
 * Title:  Count Number of Nice Subarrays (Leetcode Medium 1248)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, June, 2024
 * Method: Sliding window to find the number of nice subarrays. The window size is from k to n.
 * Result: TLE. Time complexity is O(n^2), space complexity is O(1).
 */

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int window = k;
        while (window <= n) {
            int odd = 0;
            for (int i = 0; i < window; i++) {
                if (nums[i] & 1) odd++;
            }
            if (odd == k) ans++;
            for (int i = 1; i < n - window + 1; i++) {
                if (nums[i - 1] & 1) odd--;
                if (nums[i + window - 1] & 1) odd++;
                if (odd == k) ans++;
            }
            // cout << window << ", " << ans << "\n";
            window++;
        }
        return ans;
    }
};
