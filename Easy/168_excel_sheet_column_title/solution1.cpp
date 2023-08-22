/**
 * Title:  Excel Sheet Column Title (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, August, 2023
 * Method: Math. Time Complexity: O(logn) // O(log_26(N))
 */

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while (columnNumber > 26) {
            ans += ('A' + ((columnNumber - 1) % 26));
            columnNumber -= 1;
            columnNumber /= 26;
            // cout << ans << ", " << columnNumber << "\n";
        }
        ans += ('A' + ((columnNumber - 1) % 26));
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// A = 1, 'A' + 0
// B = 2, 'A' + 1
// AZ = 52, 51 % 26 = 25, 'A' + 25 = 'Z', 51 / 26 = 1.
