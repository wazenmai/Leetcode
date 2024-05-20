/**
 * Title:  Sum of All Subset XOR Totals (Leetcode Easy 1863)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, May, 2024
 * Method: Since we want all subsets, we can simply just count the result with and without the current element.
 * Result: Time complexity is O(2^n). Space complexity is O(1).
 */

class Solution {
public:
    int recur(vector<int>& nums, int id, int res) {
        if (id == nums.size()) return res;
        int with = recur(nums, id + 1, res ^ nums[id]);
        int without = recur(nums, id + 1, res);
        return with + without;
    }

    int subsetXORSum(vector<int>& nums) {
        return recur(nums, 0, 0);
    }
};
