/**
 * Title:  Sum of Absolute Differences In A Sorted Array (Leetcode Medium 1685)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, November, 2023
 * Method: Left and right prefix sum can be used to calculate sumabsolute difference.
 * Result: Time complexity: O(3n) = O(n), Space complexity: O(2n) = O(n)
 */

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n); // left prefix sum
        vector<int> right(n); // right prefix sum
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] + nums[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] + nums[i];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = right[i] - (nums[i] * (n - i));
            ans[i] += nums[i] * (i + 1) - left[i];
        }
        return ans;
    }
};
// 2 3 5, left: 2 5 10 right: 10 8 5
// left : 2 (2 + 3) (2 + 3 + 5)
// right: (2 + 3 + 5) (3 + 5) 5

// sum | nums[i] - nums[j] | for j = 0 ~ n - 1
// 2 3 5
// 0: nums[1] + nums[2] - nums[0] - nums[0] = 8 - 2 * 2 = 4
// 1: nums[2] - nums[1] + nums[1] - nums[0] = 5 - 3 * 1 + 3 * 1 - 2 = 3
// 2: nums[2] * 2 - (nums[1] + nums[0]) = 10 - 5 = 5

// 1 4 6 8 10, left: 1 5 11 19 29, right: 29 28 24 18 10
// 0: right[1] - (nums[0] * (n - 0 - 1)) = 28 - 4 = 24
// 1: right[2] - (nums[1] * (n - 1 - 1)) + (nums[1] * 1) - left[0] = 24 - 4 * 3 + 4 - 1 = 15
