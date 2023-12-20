/**
 * Title:  Buy Two Chocolates (Leetcode Easy 2706)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, December, 2023
 */

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1 = 1000;
        int min2 = 1000;
        for (int& price: prices) {
            if (price <= min1) {
                min2 = min1;
                min1 = price;
            } else if (price <= min2) {
                min2 = price;
            }
        }
        return (money - min1 - min2 >= 0) ? money - min1 - min2 : money;
    }
};
