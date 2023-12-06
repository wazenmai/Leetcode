/**
 * Title:  Calculate Money in Leetcode Bank (Leetcode Easy 1716)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, December, 2023
 */

class Solution {
public:
    int totalMoney(int n) {
        int week = n / 7;
        int day = n % 7;
        int ans = 0;
        ans += 28 * week + 7 * week * (week - 1) / 2;
        ans += (week + 1) * day + day * (day - 1) / 2;
        return ans;
    }
};
