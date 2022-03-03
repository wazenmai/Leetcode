/**
 * Title:  Arithmetic Slices (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, Mar, 2022
 * Method: Time O(2N), make the difference array then calculate the ans
 */

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = (int)nums.size();
        if (n < 3)
            return 0;
        
        for (int i = 0; i < n - 1; i++) {
            nums[i] = nums[i + 1] - nums[i];
        }
        
        int ans = 0;
        int temp = nums[0];
        int same = 1;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == temp) {
                ++same;
                ans += (same - 1);
            } else {
                temp = nums[i];
                same = 1;
            }
        }
        return ans;
    }
};
/*
1 1 -> 1
1 1 1 -> 3
1 1 1 1 -> 6
1 1 1 1 1 -> 10
1 1 1 1 1 1 -> 15
*/
