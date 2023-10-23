/**
 * Title:  Power of Four (Leetcode Easy 342)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, October, 2023
 * Method: If a number n is power of 4, then log4(n) is an integer. log4(n) = log(n) / log(4)
 * Result: Time Complexity O(1), Space Complexity O(1)
 */

class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;
        double check = log(n) / log(4);
        return (check == (int)check);
    }
};
