/**
 * Title:  Sort Characters By Frequency (Leetcode Medium 451)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, February, 2024
 * Result: Time complexity O(nlogn), Space complexity O(n)
 */

class Solution {
public:
    static bool compare(pair<int, char>& a, pair<int, char>& b) {
        return a.first > b.first;
    }
    string frequencySort(string& s) {
        vector<int> cnt(62, 0); // A ~ Z, a ~ z, 0 ~ 9
        for (auto& c: s) {
            if (c >= 'A' && c <= 'Z') {
                cnt[c - 'A']++;
            } else if (c >= 'a' && c <= 'z') {
                cnt[c - 'a' + 26]++;
            } else {
                cnt[c - '0' + 52]++;
            }
        }
        vector<pair<int, char>> v;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0) v.emplace_back(make_pair(cnt[i], 'A' + i));
        }
        for (int i = 26; i < 52; i++) {
            if (cnt[i] != 0) v.emplace_back(make_pair(cnt[i], 'a' + i - 26));
        }
        for (int i = 52; i < 62; i++) {
            if (cnt[i] != 0) v.emplace_back(make_pair(cnt[i], '0' + i - 52));
        }
        sort(v.begin(), v.end(), compare);
        string ans = "";
        for (auto& p: v) {
            for (int i = 0; i < p.first; i++) {
                ans += p.second;
            }
        }
        return ans;
    }
};
