/**
 * Title:  Extra Characters In a String (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, Septemner, 2023
 * Method: Bottom-Up Iterative DP. Time complexity O(nml), Space complexity O(n).
 */


class Solution {
private:
    int n;
    int m;
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        m = dictionary.size();
        vector<int> memo(n + 1, n + 1); // memo[i] = minExtraChar from (i ~ n - 1).
        memo[n] = 0;
        for (int i = n - 1; i >= 0; i--) { // s
            int ans = n + 1;
            // cout << "pos " << i << ": ";
            for (int j = 0; j < m; j++) {
                if (n - i >= dictionary[j].length()) {
                    // cout << "check " << dictionary[j] << ", ";
                    int l = dictionary[j].length();
                    bool flag = true;
                    for (int k = 0; k < l; k++) {
                        if (dictionary[j][k] != s[i + k]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        ans = min(ans, memo[i + l]);
                    }
                }
            }
            memo[i] = min(ans, 1 + memo[i + 1]);
            // cout << i << ": " << memo[i] << "\n";
        }
        return memo[0];
    }
};