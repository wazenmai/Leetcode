/**
 * Title:  Word Break (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, August, 2023
 * Method: Time complexity: O(nmk). Space complexity: O(n+m).
 */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        int m = wordDict.size();
        vector<bool> dp(n + 1, false); // whether s(0...i) is a valid word
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            // cout << "pos: " << i << ": ";
            for (int j = 0; j < m; j++) {
                if (i >= wordDict[j].length()) {
                    bool flag = true;
                    int l = wordDict[j].length();
                    for (int k = 0; k < l; k++) {
                        if (s[i - l + k] != wordDict[j][k]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag && !dp[i]) {
                        // cout << wordDict[j] << ", ";
                        dp[i] = dp[i - l];
                    }
                }
            }
            // cout << dp[i] << "\n";
        }
        return dp[n];
    }
};
