/**
 * Title:  Count Subarrays with Fixed Bounds (Leetcode Hard 2444)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, March, 2024
 * Method: Store the position of num that exceed the range as cutpoint, and store the position of minK and maxK as min_pos and max_pos. If min_pos and max_pos are both found, add min(min_pos, max_pos) - cutpoint to the answer.
 * Result: Time complexity is O(n), space complexity is O(1).
 */

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        bool mincheck = false, maxcheck = false;
        int min_pos = 0, max_pos = 0;
        int cutpoint = -1;
        int n = nums.size();
        long long ans = 0;
        for (int r = 0; r < n; r++) {
            if (nums[r] < minK || nums[r] > maxK) { // cutpoint
                cutpoint = r;
                mincheck = false;
                maxcheck = false;
                continue;
            }
            if (nums[r] == minK) {
                mincheck = true;
                min_pos = r;
            }
            if (nums[r] == maxK) {
                maxcheck = true;
                max_pos = r;
            }
            if (mincheck && maxcheck) {
                ans += (min(min_pos, max_pos) - cutpoint);
            }
            // cout << nums[r] << "(" << r << "), cut=" << cutpoint;
            // cout << ", min: " << mincheck << min_pos;
            // cout << ", max: " << maxcheck << max_pos << "\n";
        }
        return ans;
    }
};

//  3 2 1 3 5 2 7 5 3 1
//      2   4     5  7
// cut=-1
