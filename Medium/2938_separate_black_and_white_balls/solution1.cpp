/**
 * Title:  Separate Black and White Balls (Leetcode Medium 2938)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, October, 2024
 * Method: Use right to record the position of leftest continuous 1s.
 * Result: Time complexity O(n). Space complexity O(1).
 */

class Solution {
public:
    long long minimumSteps(string s) {
        long long swap = 0;
        int n = s.length();
        int right = n;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') break;
            right = i;
        }
        // cout << "right: " << right << "\n";
        for (int i = right - 1; i >= 1; i--) {
            if (s[i] == '0' && s[i - 1] == '1') {
                swap += (right - i);
                s[right - 1] = '1';
                s[i - 1] = '0';
                right--;
            }
        }
        return swap;
    }
};

// 1100
// 0110110 -> 0110101 -> 011010011
// 011000111
// 010001111
