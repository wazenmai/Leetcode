/**
 * Title:  Word Break (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, August, 2023
 * Method: Trie Optimization. Time complexity: O(n^2 + mk). Build Trie O(mk), Space complexity: O(n+mk)
 */

 // Trie: dictionary tree, each dfs path is a word.
struct TrieNode {
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode(): isWord(false), children(unordered_map<char, TrieNode*>()) {}
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Make Trie from wordDict
        TrieNode* root = new TrieNode();
        for (string word: wordDict) {
            TrieNode* cur = root;
            for (char c: word) {
                if (cur->children.find(c) == cur->children.end()) {
                    cur->children[c] = new TrieNode();
                }
                cur = cur->children[c];
            }
            cur->isWord = true;
        }  

        // Use Bottom-Up DP
        vector<bool> dp(s.length(), false);
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || dp[i - 1]) {
                TrieNode* cur = root;
                for (int j = i; j < s.length(); j++) {
                    char c = s[j];
                    if (cur->children.find(c) == cur->children.end())
                        break;
                    cur = cur->children[c];
                    if (cur->isWord)
                        dp[j] = true;
                }
            }
        }
        return dp[s.length() - 1];    
    }
};
