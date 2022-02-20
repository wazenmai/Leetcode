/**
 * Title:  Single Number (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, Feb, 2022
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto& n : nums)
            ans ^= n;
        return ans;
    }
};
