/**
 * Title:  Pow(x, n) (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, July, 2023
 * Method: Time complexity O(logn)
 */

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 1)
            return x;
        if (n == 0)
            return 1;
        double ans = x;
        if (n > 0) {
            unsigned int p = 1;
            while (p < n) {
                if (n >= 2 * p) {
                    ans = ans * ans;
                    p *= 2;
                } else if (n > p) {
                    ans *= myPow(x, n - p);
                    p = n;
                }
            }
        } else { // n < 0
            ans = 1 / x;
            unsigned int p = 1;
            while (-p > n) {
                if (n <= -2 * p) {
                    ans = ans * ans;
                    p *= 2;
                } else if (n < -p) {
                    ans *= myPow(x, (int)n+p);
                    p += -(n + p);
                }
            }
        }
        return ans;
    }
};

/* pow(2, -3) */
