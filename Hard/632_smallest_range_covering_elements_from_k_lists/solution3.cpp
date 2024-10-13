/**
 * Title:  Smallest Range Covering Elements from K Lists (Leetcode Hard 632)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, October, 2024
 * Method: Optimal Brute Force. Iterate through every list and find the minimum and maximum element in the range. Increase the left bound and check whether to add the new element and adjust the right bound.
 * Result: Time complexity O(k * n) = O(nk), where k is number of lists, n is total number of elements across lists. Space complexity O(k).
 */

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<int> id(k, 0);
        vector<int> range = {0, INT_MAX};
        while (true) {
            int curMin = INT_MAX;
            int curMax = INT_MIN;
            int minListIndex = 0;
            for (int i = 0; i < k; i++) {
                if (nums[i][id[i]] < curMin) {
                    curMin = nums[i][id[i]];
                    minListIndex = i;
                }
                curMax = max(curMax, nums[i][id[i]]);
            }
            if (curMax - curMin < range[1] - range[0]) {
                range[0] = curMin;
                range[1] = curMax;
            }
            if (++id[minListIndex] == nums[minListIndex].size())
                break;
        }
        return range;
    }
};
