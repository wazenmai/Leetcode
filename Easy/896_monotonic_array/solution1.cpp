/**
 * Title:  Monotonic Array (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, September, 2023
 * Method: First check the direction, then validate the numbers. Time complexity O(N).
 */

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool dir = true; // 1: increase, 0: decrease
        int i = 0;
        int n = nums.size();
        while (i + 1 < n) {
            ++i;
            if (nums[i] == nums[i - 1]) {
                continue;
            } else if (nums[i] > nums[i - 1]) {
                dir = true;
                break;
            } else {
                dir = false;
                break;
            }
            
        }
        while (i + 1 < n) {
            ++i;
            if (dir && nums[i] < nums[i - 1]) {
                return false;
            } else if (!dir && nums[i] > nums[i - 1]){
                return false;
            }
        }
        return true;
    }
};
