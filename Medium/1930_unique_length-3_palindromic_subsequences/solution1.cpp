/**
 * Title:  Unique Length-3 Palindromic Subsequences (Leetcode Medium 1930)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, November, 2023
 * Method: Use count to record the number of each character. Use pos to record the position of each character.
    * Iterate through all characters, if the number of a character is greater than 2, then count the # of unique characters between the first and last appearance of the character.
 * Result: Time complexity: O(26n). n = length of string. n <= 1e5. Space Complexity: O(n)
 */

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> count(26, 0);
        vector<vector<int>> pos(26);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
            pos[s[i] - 'a'].emplace_back(i);
        }
        int maxappear = 0;
        for (int i = 0; i < 26; i++)
            maxappear = max(maxappear, count[i]);
        if (maxappear <= 1) return 0;

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] >= 2) {
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
            // char c = i + 'a';
            // cout << c << ": " << ans << "\n";
        }
        return ans;
    }
};
