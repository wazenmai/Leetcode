/**
 * Title:  Find All Duplicates in an Array (Leetcode Medium 442)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, March, 2024
 * Method: Use negative number to mark the number that has been visited. If visited negative number, then the original nums[i] is a duplicate number.
 * Result: Time complexity O(n), Space complexity O(1).
 */

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int id = abs(nums[i]) - 1;
            if (nums[id] < 0) {
                ans.emplace_back(abs(nums[i]));
            }
            nums[id] = -nums[id];
        }
        return ans;
    }
};
