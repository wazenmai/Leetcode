/**
 * Title:  Counting Bits (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, Sep, 2023
 * Method: Time O(N)
 */

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        int base = 0;
        int round = 0;
        for (int i = 1; i <= n; i++) {
            ans[i] = ans[base] + 1;
            if (base == round) {
                base = 0;
                round = i;
            } else {
                base++;
            }
        }
        return ans;
    }
};
