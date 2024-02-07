/**
 * Title:  Group Anagrams (Leetcode Medium 49)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, February, 2024
 * Method: Use a map to store the signature of each string, and then use the signature as the key to store the strings with the same signature. The key is made by aaabbbccc...z.
 * Result: n = |strs|, m = |strs[i]|, Time complexity O(nm), Space complexity O(nm)
 */

class Solution {
public:
    string signature(string& s) {
        vector<int> cnt(26, 0);
        for (auto& c: s) {
            cnt[c - 'a']++;
        }
        string res = "";
        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            for (int j = 0; j < cnt[i]; j++) {
                res += c;
            }
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto& str: strs) {
            m[signature(str)].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = m.begin(); it != m.end(); it++) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
