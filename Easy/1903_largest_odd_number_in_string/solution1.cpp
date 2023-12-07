/**
 * Title:  Largest Odd Number in String (Leetcode Easy 1903)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, December, 2023
 */

class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int n = num.length();
        for (int i = n - 1; i >= 0; i--) {
            if ((num[i] - '0') & 1) {
                ans.assign(num, 0, i + 1);
                break;
            }
        }
        return ans;
    }
};
