/**
 * Title:  Minimum Number of Steps to Make Two Strings Anagram (Leetcode Medium 1347)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, Janurary, 2024
 */

class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> s_cnt(26, 0);
        vector<int> t_cnt(26, 0);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            s_cnt[s[i] - 'a']++;
            t_cnt[t[i] - 'a']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (s_cnt[i] > t_cnt[i]) {
                ans += s_cnt[i] - t_cnt[i];
            }
        }
        return ans;
    }
};
