/**
 * Title:  Minimum Bit Flips to Convert Number (Leetcode Easy 2220)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, September, 2024
 */

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal;
        int ans = 0;
        while (x > 0) {
            if (x & 1) ans++;
            x >>= 1;
        }
        return ans;
    }
};
