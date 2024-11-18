/**
 * Title:  Defuse the Bomb (Leetcode Easy 1652)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, November, 2024
 */

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0) return ans;
        if (k > 0) {
            int s = 0;
            for (int i = 1; i <= k; i++) {
                s += code[i];
            }
            for (int i = 0; i < n; i++) {
                ans[i] = s;
                s -= code[(i + 1) % n];
                s += code[(i + k + 1) % n];
            }
        } else {
            k *= -1;
            int s = 0;
            for (int i = 0; i < k; i++) {
                s += code[n - 1 - i];
            }
            for (int i = 0; i < n; i++) {
                ans[i] = s;
                s -= code[(i - k + n) % n];
                s += code[i];
            }
        }
        return ans;
    }
};
