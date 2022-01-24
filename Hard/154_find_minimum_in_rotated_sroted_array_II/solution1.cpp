/**
 * Title:  Find Minimum in Rotated Sorted Array II (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, Mar, 2021
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = 5000;
        int size = nums.size();
        
        for (int i = 0; i < size; i++) {
            ans = min(ans, nums[i]);
        }
        return ans;
    }
};
