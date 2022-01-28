/**
 * Title:  Design Add and Search Words Data Structure (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, Jan, 2022
 * Method: Trie-based letter node
 */

struct WordNode {
    char letter;
    bool last;
    WordNode *next[26];
    WordNode() {
        letter = '0';
        last = false;
        for (auto& nxt : next)
            nxt = nullptr;
    }
    WordNode(char c) {
        letter = c;
        last = false;
        for (auto& nxt : next)
            nxt = nullptr;
    }
    WordNode(char c, bool end) {
        letter = c;
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
        // cout << "Add ";
        for (auto& c : word) {
            // cout << c;
            if (!cur->next[c - 'a'])
                cur->next[c - 'a'] = new WordNode(c);
            cur = cur->next[c - 'a'];
        }
        cur->last = true;
        // cout << "\n";
    }
    
    bool dfs(string& word, int index, int n, WordNode *cur) {
        if (index == n) {
            if (cur->last)
                return true;
            return false;
        }
        // cout << "  " << word[index] << " " << index << " " << cur->letter << "\n";
        if (word[index] == '.') {
            for (auto& nxt : cur->next) {
                if (nxt && dfs(word, index + 1, n, nxt))
                    return true;
            }
            return false;
        }
        if (!cur->next[word[index] - 'a'])
            return false;
        return dfs(word, index + 1, n, cur->next[word[index] - 'a']);
    }
    
    bool search(string word) {
        // cout << "Search: " << word << "\n";
        // bool ans = dfs(word, 0, word.length(), root);
        // cout << "Ans: " << ans << "\n";
        // return ans;
        return dfs(word, 0, word.length(), root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
