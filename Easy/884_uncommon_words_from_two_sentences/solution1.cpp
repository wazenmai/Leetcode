/**
 * Title:  Uncommon Words from Two Sentences (Leetcode Easy 884)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, September, 2024
 */

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m;
        s1 += " ";
        s2 += " ";
        string word = "";
        for (auto& c: s1) {
            if (c == ' ') {
                m[word]++;
                word = "";
            } else {
                word += c;
            }
        }
        for (auto& c: s2) {
            if (c == ' ') {
                m[word]++;
                word = "";
            } else {
                word += c;
            }
        }
        vector<string> ans;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == 1) {
                ans.emplace_back(it->first);
            }
        }
        return ans;
    }
};
