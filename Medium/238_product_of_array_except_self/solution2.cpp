/**
 * Title:  Product of Array Except Self (Leetcode Medium 238)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, March, 2024
 * Method: First traverse the array to get the product of all elements to the left of the current element. Then traverse the array from right to left to get the product of all elements to the right of the current element.
 * Result: Time complexity O(n), Space complexity O(1).
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
};
