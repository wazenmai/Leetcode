/**
 * Title:  Backspace String Compare (Leetcode Medium 343)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, October, 2023
 * Method: Use two pointers to compare the string from the end.
 * Result: Time complexity O(N), space complexity O(1).
 */

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1, back;
        while (true) {
            back = 0;
            while (i >= 0 && (back > 0 || s[i] == '#')) {
                back += s[i] == '#' ? 1 : -1;
                i--;
            }
            back = 0;
            while (j >= 0 && (back > 0 || t[j] == '#')) {
                back += t[j] == '#' ? 1 : -1;
                j--;
            }
            if (i >= 0 && j >= 0 && s[i] == t[j]) {
                i--;
                j--;
            } else {
                break;
            }
        }
        return i == -1 && j == -1;
    }
};
