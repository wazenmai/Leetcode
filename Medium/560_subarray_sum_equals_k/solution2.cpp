/**
 * Title:  Subarray Sum Equals k (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, Feb, 2022
 * Result: Accepted
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_sum;
        int temp_sum = 0;
        int ans = 0;
        prefix_sum[0] = 1;
        
        for (auto& x : nums) {
            temp_sum += x;
            if (prefix_sum[temp_sum - k]) {
                ans += prefix_sum[temp_sum - k];
            }
            prefix_sum[temp_sum] += 1;
        }
        return ans;
    }
};
// p[i] - p[j-1] = k
