/**
 * Title:  Minimum Changes To Make Alternating Binary String (Leetcode Easy 1758)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, December, 2023
 * Method: The answer is either 1010.. or 0101..., and the flip number sum will equal to string length.
 */

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int change1 = 0, change2 = 0;
        // change1: 1010...
        // change2: 0101...
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                if (s[i] == '1') change1++;
                else change2++;
            } else {
                if (s[i] == '0') change1++;
                else change2++;
            }
        }
        return min(change1, change2);
    }
};
