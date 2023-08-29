/**
 * Title:  Minimum Penalty for a Shop (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, August, 2023
 */

class Solution {
public:
    int bestClosingTime(string customers) {
        int ty = 0;
        for (char c: customers) {
            if (c == 'Y')
                ty++;
        }
        // cout << ty << "\n";
        
        int n = customers.length();
        // cout << n << "\n";
        int y = 0, f = 0;
        int close_time = 0;
        int penalty = n;
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'Y') {
                int temp = f + ty - y;
                if (temp < penalty) {
                    penalty = temp;
                    close_time = i;
                }
                y++;
            } else {
                int temp = f + ty - y;
                if (temp < penalty) {
                    penalty = temp;
                    close_time = i;
                }
                f++;
            }
            // cout << i << " " << customers[i] << " " << penalty << "\n";
        }
        int temp = f;
        if (temp < penalty) {
            penalty = temp;
            close_time = n;
        }
        return close_time;
    }
};
