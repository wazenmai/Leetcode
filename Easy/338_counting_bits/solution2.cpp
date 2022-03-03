/**
 * Title:  Counting Bits (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, Mar, 2022
 * Method: Time O(N), find the ordering laws of the answer, ans reuse them
 */

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(1, 0);
        int base = 1;
        int ones = 0;
        int i = 1;
        while (i <= n) {
            if (i == base) {
                ans.emplace_back(1);
                ones++;
                base *= 2;
                i++;
            }
            if (i > n)
                break;
            int m = i;
            for (int j = 0; j < m; j++) {
                ans.emplace_back(ans[j] + ones);
                i++;
                if (i > n)
                    break;
            }
        }
        return ans;
    }
};
