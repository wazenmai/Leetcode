/**
 * Title:  Missing Number (Leetcode Medium 268)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, February, 2024
 * Method: Use function to sum the numbers and add faster I/O.
 * Result: Time complexity O(n), Space complexity O(1). Runtime: 4 ms. Memory: 20.49 MB.
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int n_sum = (1 + n) * n / 2;
        return n_sum - sum; 
    }
};
