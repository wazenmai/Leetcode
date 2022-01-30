/**
 * Title:  Rotate Array (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, Jan, 2022
 * Method: O(n) memory, O(n) time
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int skip = k % n;
        vector<int> res;
        for (int i = n - skip; i < n; i++)
            res.emplace_back(nums[i]);
        for (int i = 0; i < n - skip; i++)
            res.emplace_back(nums[i]);
        nums = res;
    }
};
