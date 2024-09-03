/**
 * Title:  Sum of Digits of String After Convert (Leetcode Easy 1945)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, September, 2024
 */

class Solution {
public:
    int getLucky(string s, int k) {
        int num = 0;
        for (auto& c: s) {
            int digits = c - 'a' + 1;
            num += digits % 10;
            num += digits / 10;
        }
        k -= 1;
        if (k == 0) return num;
        while (k--) {
            int nxt = 0;
            while (num > 0) {
                nxt += num % 10;
                num /= 10;
            }
            num = nxt;
        }
        return num;
    }
};
