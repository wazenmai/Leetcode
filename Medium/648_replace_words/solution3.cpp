/**
 * Title:  Replace Words (Leetcode Medium 648)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, June, 2024
 * Method: Use Trie to store dictionary, then iterate through sentence to find the shortest prefix match. Use istream to split sentence into words.
 * Result: Time complexity is O(nw + mw), where m = # of words in sentence, w = average length of each word. Space complexity is O(nw), where n is the size of dictionary.
 */

class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode(): children(26, nullptr) {
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->isEnd = true;
    }

    string shortestRoot(string& word) {
        TrieNode* cur = root;
        int n = word.length();
        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (cur->children[c - 'a'] == nullptr) {
                return word;
            }
            cur = cur->children[c - 'a'];
            if (cur->isEnd) {
                return word.substr(0, i + 1);
            }
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        istringstream sStream(sentence);
        Trie dictTrie;
        for (auto& s: dictionary) {
            dictTrie.insert(s);
        }
        string word;
        string ans;
        while (getline(sStream, word, ' ')) {
            ans += dictTrie.shortestRoot(word) + " ";
        }
        ans.pop_back();
        return ans;
    }
};
