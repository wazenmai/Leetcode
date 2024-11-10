/**
 * Title:  Minimum Array End (Leetcode Medium 3133)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   09, November, 2024
 * Method: Optimization of solution1.cpp. -> the value of n - 1 is the number we want to fill in in the position of zero in x
 * Result: Time complexity O(logy) <= O(64). Space complexity O(logy), where x is the biggest possible long long.
 */


class Solution {
public:
    long long minEnd(int n, int x) {
        // Use a mask from bit 0 to 64, if one in x, nothing, if zero in x, then we can manipulate this bit
        // we need to let bits that = 0 in x = n - 1
        n--;
        long long ans = x;
        for (long long mask = 1; n > 0; mask <<= 1) {
            if (mask & x) continue;
            if (n & 1) {
                ans |= mask;
            }
            n >>= 1;
        }
        return ans;
    }
};
