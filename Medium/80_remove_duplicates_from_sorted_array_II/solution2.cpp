/**
 * Title:  Remove Duplicates from Sorted Array II (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   8, Feb, 2022
 * Method: O(N) time, O(1) memory -> ignore the duplicate numbers
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (auto& n : nums) {
            if (k < 2 || n > nums[k - 2]) {
                nums[k++] = n;
            }
        }
        return k;
    }
};
