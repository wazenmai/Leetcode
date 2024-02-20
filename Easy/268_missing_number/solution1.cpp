/**
 * Title:  Missing Number (Leetcode Medium 268)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, February, 2024
 * Method: Use the sum of 1 to n minus the sum of the array to get the missing number.
 * Result: Time complexity O(n), Space complexity O(1). Runtime: 16 ms. Memory: 20.29 MB.
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int sum = 0;
       for (auto& num: nums) {
           sum += num;
       }
       int n = nums.size();
       int n_sum = (1 + n) * n / 2;
       return n_sum - sum; 
    }
};
