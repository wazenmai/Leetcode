/**
 * Title:  Make String a Subsequence Using Cyclic Increments (Leetcode Medium 2825)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, December, 2024
 * Method: Greedy. It is guaranteed that matching str1's character that closer to left side for str2's character is better since it left more choices for the rest of str2.
 * Result: Time complexity O(n). Space complexity O(1).
 */

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j == m) break;
            if (str1[i] == str2[j]) {
                j++;
            } else if (str1[i] == 'z' && str2[j] == 'a') {
                j++;
            } else if (str1[i] + 1 == str2[j]) {
                j++;
            }
        }
        return (j == m) ? true : false;
    }
};
