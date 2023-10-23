/**
 * Title:  Power of Four (Leetcode Easy 342)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, October, 2023
 * Method: Recursion
 * Result: Time Complexity O(logn), Space Complexity O(1)
 */

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 0)
            return false;
        if (n == 1)
            return true;
        if (n % 4 != 0)
            return false;
        return isPowerOfFour(n / 4);
    }
};
