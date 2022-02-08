/**
 * Title:  Add Digits (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   8 Feb, 2022
 * Method: O(1) time, find the rules of numbers
 */

class Solution {
public:
    int addDigits(int num) {
        if (num == 0)
            return 0;
        return (num % 9 == 0) ? 9 : num % 9;
    }
};
