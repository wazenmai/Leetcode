/**
 * Title:  Sum of Square Numbers (Leetcode Medium 633)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, June, 2024
 * Method: Use two pointers to find the two numbers whose square sum is c.
 * Result: Time complexity is O(sqrt(c)), space complexity is O(1).
 */

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i = 1;
        long long j = sqrt(c);
        if (j * j == c) return true;
        while (i <= j) {
            long long sum = (i * i) + (j * j);
            if (sum == c) return true;
            if (sum < c) i++;
            else j--;
        }
        return false;
    }
};
