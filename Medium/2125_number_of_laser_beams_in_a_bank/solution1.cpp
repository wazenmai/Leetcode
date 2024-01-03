/**
 * Title:  Number of Laser Beans in a Bank (Leetcode Medium 2125)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, Janurary, 2024
 */

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].length();
        int last_security = 0;
        int now_security = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) { // row
            now_security = 0;
            for (int j = 0; j < m; j++) {
                if (bank[i][j] == '1') now_security++;
            }
            if (last_security > 0 && now_security > 0) {
                ans += last_security * now_security;
            }
            if (now_security != 0) {
                last_security = now_security;
            }
        }
        return ans;
    }
};
