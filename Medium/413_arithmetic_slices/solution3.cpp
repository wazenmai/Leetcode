/**
 * Title:  Arithmetic Slices (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, Mar, 2022
 * Method: Time O(N), sliding window
 */

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = (int)nums.size();
        int ans = 0;
        for (int i = 2, j = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] != nums[j] - nums[j - 1])
                j = i;
            ans += (i - j);
        }
        return ans;
    }
};
