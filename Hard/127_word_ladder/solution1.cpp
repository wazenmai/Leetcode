/**
 * Title:  Word Ladder (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, Feb, 2022
 * Method: O(n * n * 26 * w) time, O(n) space
 */

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        for (auto& w : wordList) {
            wordSet.insert(w);
        }
        if (!wordSet.count(endWord))
            return 0;
        
        queue<pair<string, int>> buffer;
        buffer.push(make_pair(beginWord, 1));
        // cout << beginWord << " 1\n";
        while (!buffer.empty()) {
            auto temp = buffer.front();
            buffer.pop();
            int n = temp.first.length();
            for (int i = 0; i < n; i++) {
                char origin = temp.first[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    temp.first[i] = c;
                    if (wordSet.count(temp.first)) {
                        if (temp.first == endWord)
                            return temp.second + 1;
                        buffer.push(make_pair(temp.first, temp.second + 1));
                        // cout << temp.first << " " << temp.second + 1 << "\n";
                        wordSet.erase(temp.first);
                    }
                }
                temp.first[i] = origin;
            }
        }
        return 0;
    }
};
