/**
 * Title:  Counting Bits (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, Mar, 2022
 * Method: Time O(16N) = O(NlogN)
 */

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i = 0; i <= n; i++) {
            int ones = 0;
            int num = i;
            for (int j = 16; j >= 0; j--) {
                ones += num / (1 << j);
                num = num % (1 << j);
            }
            // cout << i << ": " << ones << "\n";
            ans.emplace_back(ones);
        }
        return ans;
    }
};
