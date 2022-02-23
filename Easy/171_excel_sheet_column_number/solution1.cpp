/**
 * Title:  Excel Sheet Column Number (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, Feb, 2022
 */

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        for (auto& c : columnTitle) {
            sum = sum * 26 + (c - 'A' + 1);
        }
        return sum;
    }
};
