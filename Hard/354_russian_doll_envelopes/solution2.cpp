/**
 * Title:  Russian Doll Envelopes (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, Mar, 2021
 */

// pass, since I change sort to O(nlogn)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int size = envelopes.size();
        if (size == 0) return 0;

        vector<int> dp(size, 1);
        int ans = 0;
        sort(envelopes.begin(), envelopes.end());
        for (int i = 0; i < size; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }   
};
