/**
 * Title:  Majority Element (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, Feb, 2022
 * Method: O(nlogn) time, O(1) memory
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        int counter = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1])
                counter = 1;
            else
                counter++;
            if (counter > n / 2)
                return nums[i];
        }
        return nums[n - 1];
    }
};
