/**
 * Title:  Largest 3-Same-Digit Number in String (Leetcode Easy 2264)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, December, 2023
 */

class Solution {
public:
    string largestGoodInteger(string num) {
        int a = -1;
        int n = num.length();
        string c;
        for (int i = 2; i < n; i++) {
            if (num[i] == num[i - 1] && num[i - 1] == num[i - 2]) {
                if (num[i] - '0' > a) {
                    a = num[i] - '0';
                    c = num[i];
                }
            }
        }
        if (a != -1) {
            string ans = c + c + c;
            return ans;
        }
        return "";
    }
};
