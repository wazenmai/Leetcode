/**
 * Title:  Sum of Prefix Scores of Strings (Leetcode Hard 2416)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, September, 2024
 * Method: Use a Trie (prefix tree) to store the prefix of each word, use cnt to store the visited times of each node.
 * Result: Time complexity O(nm), space complexity O(nm), where n is the number of words and m is the average length of words.
 */

struct TrieNode {
    char c;
    int cnt;
    vector<TrieNode*> children;
    TrieNode(char s_, int cnt_) {
        c = s_;
        cnt = cnt_;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode(0, 0);
        for (auto& word: words) {
            TrieNode* cur = root;
            for (const char& c: word) {
                // check if c is in children
                int i = 0;
                bool find = false;
                while (i < cur->children.size()) {
                    if (cur->children[i]->c == c) {
                        find = true;
                        break;
                    }
                    i++;
                }
                if (find) {
                    cur = cur->children[i];
                    cur->cnt++;
                } else {
                    TrieNode* node = new TrieNode(c, 1);
                    cur->children.emplace_back(node);
                    cur = node;
                }
            }
        }
        vector<int> ans;
        for (auto& word: words) {
            int cnt = 0;
            TrieNode* cur = root;
            for (const char& c: word) {
                int i = 0;
                while (i < cur->children.size()) {
                    if (cur->children[i]->c == c) {
                        break;
                    }
                    i++;
                }
                cnt += cur->children[i]->cnt;
                cur = cur->children[i];
            }
            ans.emplace_back(cnt);
        }
        return ans;
    }
};
