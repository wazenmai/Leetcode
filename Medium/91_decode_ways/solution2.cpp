/**
 * Title:  Decode Ways (Leetcode Medium 91)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, December, 2023
 * Method: Tidy the code.
 * Result: Time complexity O(n), space complexity O(1)
 */

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        // category 1: end by 1 digit
        // category 2: end by 2 digits
        if (s[0] == '0') return 0;
        int count1 = 1;
        int count2 = 0;
        int pre1 = count1;
        for (int i = 1; i < n; i++) {
            pre1 = count1;
            count1 = (s[i] == '0') ? 0 : count1 + count2;
            count2 = ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6')) ? pre1 : 0;
        }
        return count1 + count2;
    }
};
