/**
 * Title:  Number of Ways to Divide a Long Corridor (Leetcode Hard 2147)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, November, 2023
 * Method: Count the difference between the last S and the first S of next group.
 * Result: Time complexity: O(n), Space complexity: O(1)
 */

class Solution {
public:
    void print(vector<pair<int, int>>& v) {
        for (auto& p: v) {
            cout << "(" << p.first << "," << p.second << ") ";
        }
        cout << "\n";
    }
    int numberOfWays(string corridor) {
        int n = corridor.size();
        int s = 0;
        int last_end = -1;
        int temp = -1;
        long long ans = 1;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            if (corridor[i] == 'S') {
                s++;
                if (temp == -1) {
                    if (last_end != -1) {
                        ans *= (i - last_end);
                        ans %= mod;
                    }
                    temp = i;
                } else {
                    last_end = i;
                    temp = -1;
                }
            }
        }
        if (s & 1 || s == 0) return 0;
        if (s == 2) return 1;
        // print(v);
        return (int)(ans % mod);
    }
};
