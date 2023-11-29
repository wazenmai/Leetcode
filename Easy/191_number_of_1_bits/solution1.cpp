/**
 * Title:  Number of 1 Bits (Leetcode Easy 191)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, November, 2023
 * Method: Built-in function, O(1)
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return popcount(n);
    }
};
