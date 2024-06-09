/**
 * Title:  Subarray Sums Divisible by K (Leetcode Medium 974)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   09, June, 2024
 * Method: Similar method as 523_continuous_subarray_sum, but need to consider the negative number to make sure it is always positive.
 * Result: Time complexity is O(n), space complexity is O(n).
 */

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixMod = 0;
        int ans = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (int i = 0; i < n; i++) {
            prefixMod = (prefixMod + nums[i] % k + k) % k;
            if (m.find(prefixMod) != m.end()) {
                ans += m[prefixMod];
            }
            // cout << nums[i] << ": " << prefixMod << " " << ans << "\n";
            m[prefixMod] += 1;
        }
        return ans;
    }
};
