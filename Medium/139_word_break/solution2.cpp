/**
 * Title:  Word Break (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, August, 2023
 * Method: Bottom-up DP. Time complexity: O(nmk), n = s.length(), m = wordDict.size(), k = word.length(). Space complexity: O(n)
 */

class Solution {
public:
    bool character_check(string s, vector<string>& wordDict) {
        vector<bool> dict_character(26, false);
        for (string word: wordDict) {
            for (char c: word)
                dict_character[c-'a'] = true;
        }
        for (char c: s) {
            if (dict_character[c-'a'] == false)
                return false;
        }
        return true;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // simple character check
        if (character_check(s, wordDict) == false)
            return false;

        vector<bool> dp(s.length(), false);
        for (int i = 0; i < s.length(); i++) {
            for (string word: wordDict) {
                if (i < word.length() - 1)
                    continue;
                if (i == word.length() - 1 || dp[i - word.length()]) {
                    if (s.substr(i - word.length() + 1, word.length()) == word) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.length() - 1];
    }
};
