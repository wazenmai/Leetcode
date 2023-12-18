/**
 * Title:  Maximum Product Difference Between Two Pairs (Leetcode Easy 1913)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, December, 2023
 * Result: Time complexity O(N)
 */

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1, max2;
        int min1, min2;
        max1 = max2 = 0;
        min1 = min2 = 1e5;
        for (int& num: nums) {
            if (num >= max1) {
                max2 = max1;
                max1 = num;
            } else if (num >= max2) {
                max2 = num;
            }
            
            if (num <= min1) {
                min2 = min1;
                min1 = num;
            } else if (num <= min2) {
                min2 = num;
            }
        }
        // cout << max1 << " " << max2 << " " << min2 << " " << min1;
        return max1 * max2 - min1 * min2;
    }
};
