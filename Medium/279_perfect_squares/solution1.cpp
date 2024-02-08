/**
 * Title:  Perfect Squares (Leetcode Medium 279)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, February, 2024
 * Method: Recursion. Since it is TLE we need some memorization of repetitive numSquares(n).
 * Result: TLE.
 */

class Solution {
public:
    int numSquares(int n) {
        int half = sqrt(n);
        if (n == half * half) {
            return 1;
        }

        int ans = n;
        for (int i = 1; i <= half; i++) {
            int temp = 1 + numSquares(n - i * i);
            ans = min(temp, ans);
        }
        return ans;
    }
};
