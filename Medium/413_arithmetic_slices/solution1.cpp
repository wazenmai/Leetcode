/**
 * Title:  Arithmetic Slices (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, Mar, 2022
 * Method: Time O(N^2)
 */

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = (int)nums.size();
        if (n < 3)
            return 0;
        int ans = 0;
        for (int i = 0; i <= n - 3; i++) {
            int difference = nums[i+1] - nums[i];
            int slice = 2;
            for (int j = i + 1; j < n - 1; j++) {
                if (nums[j + 1] - nums[j] == difference)
                    slice++;
                else
                    break;
            }
            if (slice >= 3) {
                ans += (slice - 2);
            }
        }
        return ans;
    }
};
