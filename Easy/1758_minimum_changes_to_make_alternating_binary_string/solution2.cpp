/**
 * Title:  Minimum Changes To Make Alternating Binary String (Leetcode Easy 1758)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, December, 2023
 * Method: Combine the branch condition in solution1.cpp
 */

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int change1 = 0;
        // change1: 1010...
        // change2: 0101...
        for (int i = 0; i < n; i++) {
            if (s[i] == '0' + (i & 1)) change1++;
        }
        return min(change1, n - change1);
    }
};
