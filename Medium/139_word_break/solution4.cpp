/**
 * Title:  Word Break (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, August, 2023
 * Method: Bottom up DP. dp[i] =  is it possible to form s up to a length of i. Time complexity: O(n^3 + mk). Space complexity: O(n+mk)
 */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        set<string> words(wordDict.begin(), wordDict.end());
        vector<bool> dp(n+1, false); // i means length
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && words.find(s.substr(j, i - j)) != words.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
