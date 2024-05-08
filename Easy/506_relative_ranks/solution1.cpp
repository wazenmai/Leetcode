/**
 * Title:  Relative Ranks (Leetcode Easy 506)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, May, 2024
 */

class Solution {
public:
    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> v;
        int n = score.size();
        for (int i = 0; i < n; i++) {
            v.emplace_back(make_pair(score[i], i));
        }
        sort(v.begin(), v.end(), compare);
        vector<string> ans(n);
        if (n >= 1) ans[v[0].second] = "Gold Medal";
        if (n >= 2) ans[v[1].second] = "Silver Medal";
        if (n >= 3) ans[v[2].second] = "Bronze Medal";
        for (int i = 3; i < n; i++) {
            ans[v[i].second] = to_string(i + 1);
        }
        return ans;
    }
};
