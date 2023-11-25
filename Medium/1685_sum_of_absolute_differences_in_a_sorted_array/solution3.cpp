/**
 * Title:  Sum of Absolute Differences In A Sorted Array (Leetcode Medium 1685)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, November, 2023
 * Method: Left and right sum can be calculated on the fly with total sum.
 * Result: Time complexity: O(n), Space complexity: O(n).
 */

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int total = accumulate(nums.begin(), nums.end(), 0);
        // cout << total << "\n";
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = (total - left) - (nums[i] * (n - i));
            ans[i] += nums[i] * i - left;
            left += nums[i];
        }
        return ans;
    }
};
