/**
 * Title:  Concatenated Words (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, Janurary, 2023
 * Method: Dynamic programming. Time: O(words.length()^3 * N), Space: O(words.length() * N)
 */

 // state: dp[i] whether a word prefix (0, i-1) can be created by concatenation.
 // transition: dp[i] = true if dp[j] is true and word.substr(j, i) is in dict

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> us(words.begin(), words.end());
        vector<string> ans;
        for (auto& word: words) {
            int n = word.length();
            vector<bool> dp(n + 1, false);
            dp[0] = true;
            for (int i = 1; i <= n; i++) {
                for (int j = ((i == n) ? 1 : 0); !dp[i] && j < i; j++)
                    dp[i] = dp[j] && us.count(word.substr(j, i - j));
            }
            if (dp[n])
                ans.emplace_back(word);
        }
        return ans;
    }
};
