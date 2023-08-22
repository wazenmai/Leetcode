/**
 * Title:  Excel Sheet Column Title (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, August, 2023
 * Method: Without using reverse.
 */

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber > 0) {
            columnNumber--;
            char c = ('A' + (columnNumber % 26));
            ans = c + ans;
            columnNumber /= 26;
            // cout << ans << ", " << columnNumber << "\n";
        }
        return ans;
    }
};
