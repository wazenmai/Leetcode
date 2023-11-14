/**
 * Title:  Unique Length-3 Palindromic Subsequences (Leetcode Medium 1930)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, November, 2023
 * Method: Use pos[i].size() to subsitute count[i]. Add referece to string.
 * Result: Time complexity: O(26n). n = length of string. n <= 1e5. Space Complexity: O(n)
 */

class Solution {
public:
    int countPalindromicSubsequence(string& s) {
        vector<vector<int>> pos(26);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            pos[s[i] - 'a'].emplace_back(i);
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (pos[i].size() >= 2) {
                int l = pos[i][0];
                int r = pos[i][pos[i].size() - 1];
                vector<bool> appear(26, false);
                for (int j = l + 1; j < r; j++) {
                    if (!appear[s[j] - 'a']) {
                        ans++;
                        appear[s[j] - 'a'] = true;
                    }
                }
            }
        }
        return ans;
    }
};
