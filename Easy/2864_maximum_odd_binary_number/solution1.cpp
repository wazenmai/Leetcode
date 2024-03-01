/**
 * Title:  Maximum Odd Binary Number (Leetcode Easy 2864)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, March, 2024
 */

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = -1;
        for (auto& c: s) {
            if (c == '1') ones++;
        }
        int zeros = s.length() - ones - 1;
        string ans = "";
        while (ones > 0) {
            ans += "1";
            ones--;
        }
        while (zeros > 0) {
            ans += "0";
            zeros--;
        }
        ans += "1";
        return ans;
    }
};
