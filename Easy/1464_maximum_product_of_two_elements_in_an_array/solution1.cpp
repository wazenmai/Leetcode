/**
 * Title:  Maximum Product of Two Elements in an Array (Leetcode Easy 1464)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, December, 2023
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = -1;
        int max2 = -1;
        for (int num: nums) {
            if (num >= max1) {
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max2 = num;
            }
        }
        return (max1 - 1) * (max2 - 1);
    }
};
