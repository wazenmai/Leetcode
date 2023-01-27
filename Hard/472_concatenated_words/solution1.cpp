/**
 * Title:  Concatenated Words (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, Janurary, 2023
 * Result: Wrong Answer
 */

class Solution {
private:
    int ss;
    int ls;
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> us;
        vector<string> ans;
        ss = 1e4;
        ls = 0;
        for (auto& word: words) {
            us.insert(word);
            ss = min(ss, (int)word.length());
            ls = max(ss, (int)word.length());
        }
        // cout << ss << " " << ls << "\n---\n";
        for (auto& word: words) {
            int finded = findConcatenatedWord(word, us);
            
            if (finded >= 2) {
                // cout << word << ": " << finded << "\n";
                ans.emplace_back(word);
            }
        }
        return ans;
    }

    int findConcatenatedWord(string& word, unordered_set<string>& us) {
        string temp = "";
        int n = word.length();
        // cout << "  findConcatenatedWord (" << word << ")\n";
        for (int i = 0; i < n; i++) {
            temp += word[i];
            if (temp.length() >= ss) {
                if (us.find(temp) != us.end()) {
                    // cout << "    find " << temp << "\n";
                    if (i == n - 1)
                        return 1;
                    string new_word = word.substr(i + 1, n);
                    if (new_word.length() < ss)
                        continue;
                    if (i != n - 1) { // not the last char
                        int finded = findConcatenatedWord(new_word, us);
                        if (finded > 0)// not found in substr
                            return 1 + finded;
                    }
                }
            }
            if (temp.length() == ls) {
                return 0;
            }
        }
        return 0;
    }
};
