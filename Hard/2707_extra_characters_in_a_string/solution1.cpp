/**
 * Title:  Extra Characters In a String (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, Septemner, 2023
 * Method: Top-Down Recursive DP. Time complexity O(nml), Space complexity O(n).
 */

class Solution {
private:
    int n;
    int m;
public:
    int dp(string s, vector<string>& dictionary, int start, vector<int>& memo) {
        if (start == n)
            return 0;
        if (memo[start] != n + 1)
            return memo[start];
        int ans = n + 1;

        // choose from start
        for (int i = 0; i < m; i++) {
            if (n - start >= dictionary[i].length()) {
                int l = dictionary[i].length();
                bool flag = true;
                for (int j = 0; j < l; j++) {
                    if (dictionary[i][j] != s[start + j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ans = min(ans, dp(s, dictionary, start + l, memo));
                    // cout << start << ": " << dictionary[i] << ", " << ans << "\n";
                }
            }
        }
        // not choose from start;
        ans = min(ans, 1 + dp(s, dictionary, start + 1, memo));
        return memo[start] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        m = dictionary.size();
        vector<int> memo(n, n + 1);
        return dp(s, dictionary, 0, memo);
    }
};
