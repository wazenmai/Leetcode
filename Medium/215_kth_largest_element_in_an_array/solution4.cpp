/**
 * Title:  Kth Largest Element In An Array (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, August, 2023
 * Method: Count Sort. First count the occrence of each number, then iterate from the last element of count. Only use when number range m is small. Time Complexity O(n + m). Space Complexity O(m)
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        for (int num: nums) {
            minValue = min(minValue, num);
            maxValue = max(maxValue, num);
        }

        vector<int> count(maxValue - minValue + 1, 0);
        for (int num: nums) {
            count[num - minValue]++;
        }
        int remain = k;
        for (int num = count.size() - 1; num >= 0; num--) {
            remain -= count[num];
            if (remain <= 0)
                return num + minValue;
        }
        return -1;
    }
};

// Time complexity: O(m + n), m = maxValue - minValue
// Space complexity: O(m)
