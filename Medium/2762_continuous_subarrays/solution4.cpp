/**
 * Title:  Continuous Subarrays (Leetcode Medium 2762)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, December, 2024
 * Method: Two pointer. Use N*(N+1)/2 to calculate all the subarrys within window legnth n. 
 * Result: Time complexity is O(n), space complexity is O(n). n is the number of elements in the array. Although we iteratly move left pointer, each index would only visit at most twice.
 */

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int mi = nums[0];
        int mx = nums[0];
        long long window = 0;
        long long ans = 0;
        for (int r = 0; r < n; r++) {
            mi = min(mi, nums[r]);
            mx = max(mx, nums[r]);
            if (mx - mi > 2) {
                // calculate window but not include nums[r]
                window = r - l;
                ans += (window * (window + 1) / 2);
                // start a new window at cur position
                l = r;
                mi = mx = nums[r];
                // expand left boundary
                while (l > 0 && abs(nums[r] - nums[l - 1]) <= 2) {
                    l--;
                    mi = min(mi, nums[l]);
                    mx = max(mx, nums[l]);
                }
                // remove overcounted subarrays
                if (l < r) {
                    window = r - l;
                    ans -= (window * (window + 1) / 2);
                }
            }
        }
        // add subarrays for final
        window = n - l;
        ans += (window * (window + 1) / 2);
        return ans;
    }
};
