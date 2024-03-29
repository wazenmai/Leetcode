/**
 * Title:  Count Subarrays Where Max Element Appears at Least K Times (Leetcode Medium 2962)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, March, 2024
 * Method: Use vector to store the index of max element in nums. If the size of vector is larger than k, then we can calculate the number of subarrays that satisfy the condition.
 */

#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
static const auto fast = []() { std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0); return 0; } ();

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // Get maximum element in nums
        int max_num = *max_element(nums.begin(), nums.end());
        
        // Count # of subarrays
        long long ans = 0;
        int n = nums.size();
        vector<int> d;
        for (int r = 0; r < n; r++) {
            if (nums[r] == max_num) {
                d.emplace_back(r);
            }
            if (d.size() >= k) {
                ans += (d[d.size() - k] + 1);
            }
        }
        return ans;
    }
};
