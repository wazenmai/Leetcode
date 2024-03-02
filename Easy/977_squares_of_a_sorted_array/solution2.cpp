/**
 * Title:  Squares of a Sorted Array (Leetcode Easy 977)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, March, 2024
 * Method: Use left and right pointer to compare the absolute value of the left and right pointer, and put the larger one into the answer array.
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            if (abs(nums[left]) < abs(nums[right])) {
                ans[i] = nums[right] * nums[right];
                right--;
            } else {
                ans[i] = nums[left] * nums[left];
                left++;
            }
        }
        return ans;
    }
};
