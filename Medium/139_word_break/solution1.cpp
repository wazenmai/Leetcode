/**
 * Title:  Word Break (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, August, 2023
 * Method: Top-down DP. Time complexity: O(nmk), n = s.length(), m = wordDict.size(), k = word.length(). Space complexity: O(n)
 */

// Top-Down DP 
// dp[i]: whether it is possible to build string[0, i - 1] using wordDict

class Solution {
private:
    int n;
    string s;
    vector<string> wordDict;
    vector<int> memo;
public:
    bool check(int i) {
        if (i < 0) return true;
        if (memo[i] != -1)
            return (memo[i] == 1);
        for (string word: wordDict) {
            int l = word.length();
            if (i + 1 - l < 0)
                continue;
            if (s.substr(i - l + 1, l) == word && check(i - l)) {
                memo[i] = 1;
                return true;
            }
        }
        memo[i] = 0;
        return false;
    }

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

        // initialization
        memo = vector(s.length(), -1);
        this->wordDict = wordDict;
        this->s = s;
        return check(s.length() - 1);
    }
};
