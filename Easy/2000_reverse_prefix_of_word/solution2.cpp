/**
 * Title:  Reverse Prefix of Word (Leetcode Easy 2000)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, May, 2024
 */

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.length();
        string ans = "";
        bool rev = false;
        for (int i = 0; i < n; i++) {
            ans += word[i];
            if (!rev && word[i] == ch) {
                reverse(ans.begin(), ans.end());
                rev = true;
            }
        }
        return ans;
    }
};
