/**
 * Title:  Count All Valid Pickup and Delivery Options (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, Sep, 2023
 * Method: There are total 2n element needs to permute, but the order of (P, D) can not be change, so we need to devide 2.
 *         Therefore ans = ((2n)!) / (2^n)
 */

class Solution {
public:
    int countOrders(int n) {
        if (n == 1)
            return 1;
        int mod = 1e9 + 7;
        int devide = n;
        n *= 2;
        long long ans = n;
        // cout << n << ": " << ans << "\n";
        while (--n) {
            if (devide > 0 && !(n&1)) {
                int temp = n;
                while (!(temp & 1) && devide > 0) {
                    temp /= 2;
                    --devide;
                }
                ans *= temp;
            } else {
                ans *= n;
            }
            ans %= mod;
            // cout << n << ": " << ans << ", " << devide << "\n";
        }
        while (devide--) {
            ans /= 2;
        }
        return ans;
    }
};
