/**
 * Title:  Rotate Array (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, Jan, 2022
 * Method: O(1) memory, O(n) time. First reverse whole array, then reverse first k and leaving part respectively.
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
