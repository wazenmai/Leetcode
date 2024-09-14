/**
 * Title:  Longest Subarray With Maximum Bitwise AND (Leetcode Medium 2419)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, September, 2024
 * Method: To get the maximum bitwise AND, we need to find the maximum number in the array.
 */

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_num = nums[0];
        int len = 0;
        int ans = 0;
        for (int num: nums) {
            if (num == max_num) {
                len++;
                ans = max(ans, len);
            } else if (num > max_num) {
                max_num = num;
                len = 1;
                ans = 1;
            } else {
                len = 0;
            }
        }
        return ans;
    }
};
