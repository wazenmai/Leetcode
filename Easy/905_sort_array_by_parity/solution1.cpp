/**
 * Title:  Sort Array By Parity (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, September, 2023
 */

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!(nums[i] & 1)) {
                ans.emplace_back(nums[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] & 1) {
                ans.emplace_back(nums[i]);        
            }
        }
        return ans;
    }
};
