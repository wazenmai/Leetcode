/**
 * Title:  Majority Element (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, Feb, 2022
 * Method: O(n) time, O(1) memory
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int count = 1;
        int n = (int)nums.size();
        for (int i = 1; i < n; i++) {
            if (count == 0) {
                count++;
                major = nums[i];
            } else if (major == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
        return major;
    }
};
