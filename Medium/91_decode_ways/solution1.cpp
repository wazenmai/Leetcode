/**
 * Title:  Decode Ways (Leetcode Medium 91)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, December, 2023
 * Method: There are two categories of decodings, one ends with 1 digit, the other ends with 2 digits.
    *      Category 1: end by 1 digit, it can be transformed from last category 1 and category 2 if the digit i is not 0
    *      Category 2: end by 2 digits, it can be transformed from last category 1 if the digit i - 1 is 1 or i - 1 is 2 and i is between 0 and 6
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
        for (int i = 1; i < n; i++) {
            int pre1 = count1;
            if (s[i] != '0') {
                count1 = count1 + count2;
            } else {
                count1 = 0;
            }
            if (s[i - 1] == '1') {
                count2 = pre1;
            } else if (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6') {
                count2 = pre1;
            } else {
                count2 = 0;
            }
            // cout << i << ": " << s[i] << ", " << count1 << " " << count2 << "\n";
        }
        return count1 + count2;
    }
};
