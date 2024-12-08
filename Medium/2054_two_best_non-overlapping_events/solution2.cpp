/**
 * Title:  Two Best Non-Overlapping Events (Leetcode Medium 2054)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, December, 2024
 * Method: Sort the events by start time and end time. Iterating throgh the start time, find the maximum value with endtime before it.
 * Result: Time complexity is O(n + 2nlogn + n) = O(nlogn). Space complexity is O(n).
 */

class Solution {
public:
    int maxTwoEvents(const vector<vector<int>>& events) {
        int n = events.size();
        vector<pair<int, int>> st;
        vector<pair<int, int>> ed;
        for (auto& e: events) {
            st.emplace_back(make_pair(e[0], e[2]));
            ed.emplace_back(make_pair(e[1], e[2]));
        }
        sort(st.begin(), st.end());
        sort(ed.begin(), ed.end());
        // Iterate through st, find the maximum value with endtime before it
        int j = 0, max_v_left = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && ed[j].first < st[i].first) {
                max_v_left = max(max_v_left, ed[j].second);
                j++;
            }
            ans = max(ans, st[i].second + max_v_left);
        }
        return ans;
    }
};
