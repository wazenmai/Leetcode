/**
 * Title:  Number of Ways to Form a Target String Given a Dictionary (Leetcode Hard 1639)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, December, 2024
 * Method: DP. Need to transform words to frequency array that count each character's frequency appearing at each position.
 * Result: Time complexity O(nk + nm). Space complexity O(n). k is the number of words, n is the length of the longest word, m is the length of the target string.
 */

class Solution {
private:
    int mod;
    int max_len;
    int target_len;
public:
    int helper(vector<vector<int>>& freq, string& target, int i, int j, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];
        if (j == target.length()) return 1;
        if (i == max_len || target_len - j > max_len - i) return 0;
        long long now_temp = 0;
        if (freq[target[j] - 'a'][i] > 0) {
            now_temp += (long long)freq[target[j] - 'a'][i] * helper(freq, target, i + 1, j + 1, dp);
            now_temp %= mod;
        }
        now_temp += helper(freq, target, i + 1, j, dp);
        now_temp %= mod;
        // cout << "dp[" << i << "][" << j << "]=" << now_temp << "\n";
        return dp[i][j] = (int)now_temp;
    }
    void print(vector<vector<int>>& freq) {
        for (int i = 0; i < max_len; i++) {
            cout << i << ": ";
            for (int j = 0; j < 26; j++) {
                cout << freq[j][i] << ",";
            }
            cout << "\n";
        }
    }
    int numWays(vector<string>& words, string target) {
        vector<vector<int>> freq(26, vector<int>(1001, 0));
        mod = 1e9 + 7;
        max_len = 0;
        target_len = target.length();
        for (auto& word: words) {
            for (int i = 0; i < word.length(); i++) {
                freq[word[i] - 'a'][i]++;
            }
            max_len = max(max_len, (int)word.length());
        }
        // cout << max_len << "\n";
        // print(freq);
        vector<vector<int>> dp(max_len + 1, vector<int>(target.length() + 1, -1));
        return helper(freq, target, 0, 0, dp);
    }
};

// freq[26][n], [i][j] = frequency of character i appears at pos j
// dp[i][j] = # of matched of target[j:] with words[i:] from freq
