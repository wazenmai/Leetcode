/**
 * Title:  Product of Array Except Self (Leetcode Medium 238)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, March, 2024
 * Method: Use two arrays to store the product of all elements to the left and right of the current element. Then multiply the two arrays to get the answer.
 * Result: Time complexity O(n), Space complexity O(n).
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
            right[n - i - 1] = right[n - i] * nums[n - i];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};
