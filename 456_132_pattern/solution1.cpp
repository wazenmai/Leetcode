/**
 * Title:  132 Pattern (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, Mar, 2021
 */

// O(n^3), TLE
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.empty())
            return false;
        
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            for (int j = i+1; j < size; j++) {
                for (int k = j+1; k < size; k++) {
                    if (nums[i] < nums[k] && nums[k] < nums[j] && nums[i] < nums[j])
                        return true;
                }
            }
        }
        return false;
    }
};
