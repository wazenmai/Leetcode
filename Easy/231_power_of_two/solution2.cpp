/**
 * Title:  Power of Two (Leetcode Easy 231)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, February, 2024
 * Method: Since power of two must > 0, and number of power of two forms like 1000...0, and n - 1 forms like 0111...1, so n & (n - 1) must be 0.
 * Result: Time complexity O(1), Space complexity O(1)
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0) && ((n & (n - 1)) == 0);
    }
};
