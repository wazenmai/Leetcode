/**
 * Title:  Frequency of the Most Frequent Element (Leetcode Medium 1838)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, November, 2023
 * Method: Sort the array and find the maximum window size that the operation < k.
    * right - left + 1 = the size of the window, and we iterate right from 0 to n and move left to right when the operation > k.
 * Result: Time complexity O(nlogn), space complexity O(1)
 */

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return 1;
        
        sort(nums.begin(), nums.end());
        int left = 0;
        long long cur = 0;
        for (int right = 0; right < n; right++) {
            long target = nums[right];
            cur += target;
            if (target * (right - left + 1) - cur > k) {
                cur -= nums[left];
                left++;
            }
        }
        return n - left;
    }
};
