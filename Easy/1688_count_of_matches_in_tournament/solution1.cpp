/**
 * Title:  Count of Matches in Tournament (Leetcode Easy 1688)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, December, 2023
 */

class Solution {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while (n > 1) {
            if (n & 1) {
                ans += (n / 2);
                n = n / 2 + 1;
            } else {
                ans += (n / 2);
                n /= 2;
            }
        }
        return ans;
    }
};

