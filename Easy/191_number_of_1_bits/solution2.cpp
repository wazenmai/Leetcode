/**
 * Title:  Number of 1 Bits (Leetcode Easy 191)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, November, 2023
 * Method: Recursion.
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return n == 0 ? 0 : (n & 1) + hammingWeight(n >> 1);
    }
};
