/**
 * Title:  Distinct Subsequences (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, September, 2023
 */

class Solution {
public:
    int numDistinct(string s, string t) {
        int mod = 1e9 + 7;
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); // dp[i][j] = s(0~i-1), t(0~j-1)'s numDistinct
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        for(int j = 1; j <= m; j++) dp[0][j] = 0;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
         return dp[n][m];
    }
};
