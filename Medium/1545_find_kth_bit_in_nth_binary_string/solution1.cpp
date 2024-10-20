/**
 * Title:  Find Kth Bit in Nth Binary String (Leetcode Medium 1545)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, October, 2024
 * Method: Simulate the process of generating string. The length of S(n) is 2^n - 1.
 * Result: Time complexity O(n). Space complexity O(2^n).
 */

class Solution {
public:
    string invert(string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            s[i] = ((s[i] - '0') ^ 1) + '0';
        }
        return s;
    }
    char findKthBit(int n, int k) {
        int i = 0;
        long base = 1;
        while (k > base) {
            base *= 2;
            i++;
        }
        string s = "0";
        for (int j = 0; j < i; j++) {
            string inv = invert(s);
            reverse(inv.begin(), inv.end());
            s = s + "1" + inv;
        }
        return s[k - 1];
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