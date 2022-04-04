/**
 * Title:  Next Permutation (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, April, 2022
 * Method: https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = (int)nums.size();
        int rp = -1;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                rp = i - 1;
                break;
            }
        }
        
        if (rp == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] > nums[rp]) {
                int temp = nums[i];
                nums[i] = nums[rp];
                nums[rp] = temp;
                break;
            }
        }
        
        // reverse subarray
        reverse(nums.begin() + rp + 1, nums.end());
        return;
    }
};
