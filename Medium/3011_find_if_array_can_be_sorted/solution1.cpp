/**
 * Title:  Find if Array Can Be Sorted (Leetcode Medium 3011)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, November, 2024
 * Method: Since we can only swap adjacent elements with same number of set bits, use a vector to store the largest number in the previous group, if cureent number is smaller than the largest number in the previous group, return false.
 * Result: Time complexity is O(n), space complexity is O(n).
 */

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        // same set bit in same group
        // righter number must be larger
        int large_num = nums[0];
        int prev_bit = __builtin_popcount(nums[0]);
        vector<int> v;
        v.emplace_back(0);
        for (int i = 1; i < n; i++) {
            int bit = __builtin_popcount(nums[i]);
            if (bit == prev_bit) {
                large_num = max(nums[i], large_num);
            } else {
                prev_bit = bit;
                v.emplace_back(large_num);
                large_num = nums[i];
            }
            if (nums[i] < v.back()) return false;
        }
        return true;
    }
};
