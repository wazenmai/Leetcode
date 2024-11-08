/**
 * Title:  Maximum XOR for Each Query (Leetcode Medium 1497)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, November, 2024
 * Method: To get the maximum number by xor, we want setbit as many as possible, so we want all_xor ^ k to be all ones (under < 2^maximumbit constraint). 
 *         0 ^ x = x, 1 ^ x = ~x. So we let k to be maximumnumber of all ones. Then we can get the maximum number by xor. That's the number which xor with all_xor can get maximum number.
 * Result: Time complexity is O(n), space complexity is O(n).
 */

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int all_xor = 0;
        for (auto& num: nums) {
            all_xor ^= num;
        }
        // cout << "all_xor: " << all_xor << "\n";
        vector<int> ans(n);
        int k = 1;
        for (int i = 0; i < maximumBit - 1; i++) {
            k <<= 1;
            k += 1;
        }
x        // cout << "k: " << k << "\n";
        for (int i = 0; i < n; i++) {
            ans[i] = all_xor ^ k;
            all_xor ^= nums[n - 1 - i];
        }
        return ans;
    }
};
