/**
 * Title:  Count All Valid Pickup and Delivery Options (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, Mar, 2022
 * Method: We could see one (D, P) as a group and the order won't change. So the answer will be C^n_2 * C^(n-2)_2 ... C^2_2
 */

class Solution {
public:
    int countOrders(int n) {
        long long int ans = 1;
        for (int i = 2; i <= 2 * n; i += 2) {
            ans = ans * (i * (i - 1) / 2) % 1000000007;
        }
        int order = ans % 1000000007;
        return order;
    }
};
