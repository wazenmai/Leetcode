/**
 * Title:  Find All Anagrams in a String (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   2, Feb, 2022
 * Result: TLE
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        map<char, int> p_dict;
        map<char, int> s_dict;
        for (auto& c : p) {
            if (p_dict.find(c) != p_dict.end())
                p_dict[c] += 1;
            else
                p_dict[c] = 1;
        }
        int n = s.length();
        int m = p.length();
        bool flag = true;
        for (int i = 0; i < n; i++) {
            flag = true;
            // cout << "check: ";
            for (int j = i; j < m + i; j++) {
                // cout << s[j] << " ";
                if (p_dict.find(s[j]) == p_dict.end()) {
                    flag = false;
                    break;
                } else {
                    if (s_dict.find(s[j]) == s_dict.end())
                        s_dict[s[j]] = 1;
                    else
                        s_dict[s[j]] += 1;
                    if (s_dict[s[j]] > p_dict[s[j]]) {
                        flag = false;
                        break;
                    }
                }
            }
            // cout << flag << "\n";
            if (flag)
                ans.emplace_back(i);
            s_dict.clear();
        }
        return ans;
    }
};
