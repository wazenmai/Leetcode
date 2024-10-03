/**
 * Title:  Make Sum Divisible by P (Leetcode Medium 1590)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, October, 2024
 * Method: Prefix sum: the sum of subarray [i, j] is prefix[j + 1] - prefix[i]. Mod: (a + b) % p = (a % p + b % p) % p.
 *         By getting the sum of whole array, we know the subarray sum should make sure tha (sum - 'subarray sum') % p = 0. -> subarray_sum = target = sum % p.
 *         We can get each subarray sum by prefix sum, for a subarray [i, j], we want to find the subarray that (prefix[j + 1] - prefix[i]) % p = target. -> (target + prefix[i]) % p = prefix[j + 1] % p.
 *         So we could iterate from right to left, use a map to record the prefix sum and its index, and find the subarray that equals (target + prefix[i]) % p.
 * Result: Time complexity is O(n), space complexity is O(n).
 */


class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        unordered_map<int, int> m;
        vector<long long> prefix_sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix_sum[i + 1] = (prefix_sum[i] + (nums[i] % p)) % p;
        }
        int target = prefix_sum[n] % p;
        if (target == 0) return 0;
        int ans = n;
        m[prefix_sum[n]] = n;
        for (int i = n - 1; i >= 0; i--) {
            int t = (target + prefix_sum[i]) % p;
            if (m.find(t) != m.end()) {
                ans = min(ans, m[t] - i);
            }
            m[prefix_sum[i]] = i;

        }
        return (ans == n) ? -1 : ans;
    }
};

// sum = prefix[j + 1] - prefix[i]
// target = (A - B) % p
// A = (B + target) % p


// p = 6
// s = 10
// 3,1,4,2
// 0,3,4,8,10, target = 4
// 0 1 2 3 4