/**
 * Title:  Valid Parenthesis String (Leetcode Medium 678)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, April, 2024
 * Method: Two pointers. We iterate from the beginning and the end of the string at the same time.
 * Result: Time complexity is O(n), space complexity is O(1).
 */

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int left = 0, right = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '*') {
                left++;
            } else {
                left--;
            }
            if (s[n - i - 1] == ')' || s[n - i - 1] == '*') {
                right++;
            } else {
                right--;
            }
            if (left < 0 || right < 0) return false;
        }
        return true;
    }
};
