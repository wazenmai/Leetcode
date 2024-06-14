/**
 * Title:  Minimum Increment to Make Array Unique (Leetcode Easy 3110)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, June, 2024
 * Method: First sort. Then traverse the array and check if the current element is less than or equal to the previous element. If so, add the difference between the previous element and the current element plus one to the answer. Finally, update the current element to the previous element plus one.
 * Result: Time complexity O(nlogn), Space complexity O(1).
 */

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                ans += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return ans;
    }
};
