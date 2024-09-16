/**
 * Title:  Minimum Time Difference (Leetcode Medium 539)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, September, 2024
 * Method: Use pair to store hour and minutes, then sort the vector. Remember to consider the difference between the first and the last time.
 */

class Solution {
private:
    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<pair<int, int>> v;
        for (auto& time: timePoints) {
            v.emplace_back(make_pair(stoi(time.substr(0, 2)), stoi(time.substr(3, 2))));
        }
        sort(v.begin(), v.end(), compare);
        int ans = 24 * 60;
        int n = v.size();
        for (int i = 0; i < n - 1; i++) {
            if (v[i + 1].first == v[i].first) {
                ans = min(ans, v[i + 1].second - v[i].second);
            } else {
                int diff1 = (v[i + 1].first - v[i].first) * 60 + v[i + 1].second - v[i].second;
                int diff2 = (v[i].first + 24 - v[i + 1].first) * 60 + v[i].second - v[i + 1].second;
                ans = min(ans, min(diff1, diff2));
            }
        }
        ans = min(ans, (v[0].first + 24 - v.back().first) * 60 + v[0].second - v.back().second);
        return ans;
    }
};
