/**
 * Title:  Find Kth Bit in Nth Binary String (Leetcode Medium 1545)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, October, 2024
 * Method: Use recursion. If it is in the middle, return 1. If it is at the left side, find S(n - 1), if it is at the right side, flip it and find S(n - 1).
 */

class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        int len = (1 << n) - 1;
        int mid = len / 2 + 1; // since it is count from 1
        if (k == mid) return '1';
        if (k < mid) return findKthBit(n - 1, k);
        char bit = findKthBit(n - 1, len - k + 1); // if it is at the right side, flip it
        return bit == '0' ? '1' : '0';
    }
};
// S3=011-1-001, 0111001
// S4=011-1-001-1-0110001
// S4=011100110110001
//    012345678901234
// 1, 3, 7, 15, 31, 63
// S5=011100110110001-1-011100100110001
// S6=011100110110001-1-011100100110001-1-011100110110001-0-011100100110001
// S7=011100110110001-1-011100100110001-1-011100110110001-0-011100100110001-1
//   -011100110110001-1-011100100110001-0-011100110110001-0-011100100110001

// 1, 3, 7, 15