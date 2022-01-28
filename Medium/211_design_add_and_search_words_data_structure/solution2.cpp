/**
 * Title:  Design Add and Search Words Data Structure (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, Jan, 2022
 */

struct WordNode {
    bool last;
    WordNode *next[26];
    WordNode() {
        last = false;
        for (auto& nxt : next)
            nxt = nullptr;
    }
    WordNode(bool end) {
        last = end;
        for (auto& nxt : next)
            nxt = nullptr;
    }
};

class WordDictionary {
private:
    WordNode *root;
public:
    WordDictionary() {
        root = new WordNode();
    }
    
    void addWord(string word) {
        WordNode *cur = root;
        for (auto& c : word) {
            if (!cur->next[c - 'a'])
                cur->next[c - 'a'] = new WordNode();
            cur = cur->next[c - 'a'];
        }
        cur->last = true;
    }
    
    bool dfs(string& word, int index, WordNode *cur) {
        if (index == word.length()) {
            if (cur->last)
                return true;
            return false;
        }
        if (word[index] == '.') {
            for (auto& nxt : cur->next) {
                if (nxt && dfs(word, index + 1, nxt))
                    return true;
            }
            return false;
        }
        if (!cur->next[word[index] - 'a'])
            return false;
        return dfs(word, index + 1, cur->next[word[index] - 'a']);
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
