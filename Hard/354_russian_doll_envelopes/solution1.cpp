/**
 * Title:  Russian Doll Envelopes (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, Mar, 2021
 */

 // failed TLE

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int size = envelopes.size();
        vector<int> dp(size, 1);
        int temp1, temp2; 
        int ans = 0;

        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (envelopes[i][0] > envelopes[j][0]) {
                    temp1 = envelopes[i][0];
                    temp2 = envelopes[i][1];
                    envelopes[i][0] = envelopes[j][0];
                    envelopes[i][1] = envelopes[j][1];
                    envelopes[j][0] = temp1;
                    envelopes[j][1] = temp2;
                } else if (envelopes[i][0] == envelopes[j][0] && envelopes[i][1] < envelopes[j][1]) {
                    temp1 = envelopes[i][0];
                    temp2 = envelopes[i][1];
                    envelopes[i][0] = envelopes[j][0];
                    envelopes[i][1] = envelopes[j][1];
                    envelopes[j][0] = temp1;
                    envelopes[j][1] = temp2;
                }
            }
        }
        for (int i = 0; i < size; i++) {
            printf("%d, %d\n", envelopes[i][0], envelopes[i][1]);
        }

        for (int i = size - 1; i >= 0; i--) {
            for (int j = size - 1; j > i; j--) {
                if (envelopes[j][1] > envelopes[i][1]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            ans = max(dp[i], ans);
        }

        return ans;
    }
};
