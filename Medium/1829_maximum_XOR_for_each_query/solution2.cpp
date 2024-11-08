/**
 * Title:  Maximum XOR for Each Query (Leetcode Medium 1497)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, November, 2024
 * Method: Instead of calculating all_xor first, we calculate all_xor step by step and fill the answer in ans[n - 1 - i].
 * Result: Time complexity is O(n), space complexity is O(n).
 */

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int k = (1 << maximumBit) - 1;
        int all_xor = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            all_xor ^= nums[i];
            ans[n - 1 - i] = all_xor ^ k;
        }
        return ans;
    }
};
