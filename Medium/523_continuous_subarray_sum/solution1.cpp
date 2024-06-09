/**
 * Title:  Continuous Subarray Sum (Leetcode Medium 523)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, June, 2024
 * Method: Use prefix sum to calculate the sum of subarray, if sum(i + 1 ~ j) = prefix[j] - prefix[i] is divisible by k.
 *         Then let prefix[j] = Q1 * k + R1, prefix[i] = Q2 * k + R2. Then prefix[j] - prefix[i] = (Q1 - Q2) * k + R1 - R2, which is divisible by k. So R1 = R2 means sum(i + 1 ~ j) is divisible by k.
 *         Use a hashmap to store the prefix sum mod k and its index. If the same mod appears again, check if the length of subarray is greater than 1.
 * Result: Time complexity is O(n), space complexity is O(n).
 */


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int n = nums.size();
        int prefixMod = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < n; i++) {
            prefixMod = (prefixMod + nums[i]) % k;
            if (m.find(prefixMod) != m.end()) {
                if (i - m[prefixMod] > 1) return true;
            } else {
                m[prefixMod] = i;
            }
        }
        return false;
    }
};

