/**
 * Title:  Valid Parenthesis String (Leetcode Medium 678)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, April, 2024
 * Method: Top-Down DP-Memorization. For '*', we need to consider 3 cases: treat like '(', treat like ')', and treat like empty.
    * If we reach the end of the string, we need to check if the number of '(' is 0.
 * Result: Time complexity is O(n^2), space complexity is O(n^2).
 */

class Solution {
public:
    bool isValidString(int id, int cnt, const string& str, vector<vector<int>>& dp) {
        // cout << "(" << id << ", " << cnt << ")\n";
        if (id == str.length()) return (cnt == 0); // reach the end
        if (dp[id][cnt] != -1) return dp[id][cnt]; // visited

        bool isValid = false;
        if (str[id] == '*') {
            isValid |= isValidString(id + 1, cnt + 1, str, dp); // treat like '('
            if (cnt != 0) {
                isValid |= isValidString(id + 1, cnt - 1, str, dp); // treat like ')'
            }
            isValid |= isValidString(id + 1, cnt, str, dp);
        } else if (str[id] == '(') {
            isValid |= isValidString(id + 1, cnt + 1, str, dp);
        } else if (cnt > 0) {
            isValid |= isValidString(id + 1, cnt - 1, str, dp);
        }
        return dp[id][cnt] = isValid;
    }
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        return isValidString(0, 0, s, dp);
    }
};
// Top-Down DP-Memorization
// dp[i][j] = at end of i-th character contain j '('
// dp[i][j] = 1 if contain, 0 if doesn't contain
