/**
 * Title:  Find Common Characters (Leetcode Easy 1002)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, June, 2024
 */

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> cnt(26, 0);
        for (auto& c: words[0]) {
            cnt[c - 'a']++;
        }
        int n = words.size();
        for (int i = 1; i < n; i++) {
            vector<int> cur(26, 0);
            for (auto& c: words[i]) {
                cur[c - 'a']++;
            }
            for (int j = 0; j < 26; j++) {
                cnt[j] = min(cur[j], cnt[j]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            for (int j = 0; j < cnt[i]; j++) {
                string s = "";
                s += c;
                ans.emplace_back(s);
            }
        }
        return ans;
    }
};
