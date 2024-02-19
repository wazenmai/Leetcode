/**
 * Title:  Power of Two (Leetcode Easy 231)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, February, 2024
 * Method: Use recursion.
 * Result: Time complexity O(logn), Space complexity O(logn) - call recursion times.
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        if (n == 1) return true;
        if (! (n & 1))
            return isPowerOfTwo(n / 2);
        return false;
    }
};
