/**
 * Title:  Concatenated Words (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, Janurary, 2023
 * Method: DFS. Time O(word.length()^3 * N). Space O(word.length() * M)
 */

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> us(words.begin(), words.end());
        vector<string> ans;
        for (auto& word: words) {
            vector<bool> visited(word.length()); // default: false
            if (dfs(word, 0, visited, us)) {
                ans.emplace_back(word);
            }
        }
        return ans;
    }

    bool dfs(string& word, int length, vector<bool>& visited, unordered_set<string>& us) {
        if (length == word.length())
            return true;
        if (visited[length])
            return false;
        visited[length] = true;
        for (int i = word.length() - (length == 0 ? 1 : 0); i > length; i--) {
            if (us.count(word.substr(length, i - length)) && dfs(word, i, visited, us))
                return true;
        }

    }
};
