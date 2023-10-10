/**
 * Title: Minimum Number of Operations to Make Array Continuous (Leetcode Hard 2009)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, October, 2023
 * Method: Sliding Window, First sort the array, then use two pointers to find the maximum continuous subarray
 * Result: Time Complexity O(nlogn), Space Complexity O(1)
 */

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int m = nums.size(); // unique array size
        while (j < m) {
            // cout << "(" << i << "," << nums[i] << "), (" << j << "," << nums[j] << ")\n";
            if (nums[i] + n <= nums[j]) {
                i++;
            }
            j++;
        }
        return n - j + i;
    }
};
