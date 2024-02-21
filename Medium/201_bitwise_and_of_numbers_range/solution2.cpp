/**
 * Title:  Bitwise AND of Numbers Range (Leetcode Medium 201)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, February, 2024
 * Method: Find the common leftmost bits of left and right, and then left shift the result to the right.
 * Result: Time complexity O(logn), Space complexity O(1)
 */

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == right || left == 0) return left;
        int shift = 0;
        // Find common leftmost bits
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
    }
};
