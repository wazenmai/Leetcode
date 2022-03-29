/**
 * Title:  Find the Duplicated Number (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, Mar, 2022
 * Method: if it has duplicate, then it must meet -1.
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int idx = 0;
        int num;
        while (nums[idx] != -1) {
            num = nums[idx];
            nums[idx] = -1;
            idx = num;
            // cout << num << "\n";
        }
        return num;
    }
};
