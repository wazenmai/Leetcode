/**
 * Title:  Two Best Non-Overlapping Events (Leetcode Medium 2054)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, December, 2024
 * Method: Sort the events by end time and use a max-heap to store the events with value and start-time, if the start-time is less than the current end-time, pop the event from the heap. Then, we can get the maximum value of the two events.
 * Result: Time complexity is O(nlogn + nlogn + nlogn), where first nlogn for soring, second for max-heap, third for iterate through events and pop the element from max-heap. Space complexity is O(n).
 */

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        priority_queue<pair<int, int>> pq; // max-heap (value, start-time)
        for (auto& e: events) {
            pq.push(make_pair(e[2], e[0]));
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (!pq.empty() && pq.top().second <= events[i][1]) {
                pq.pop();
            }
            if (pq.empty()) {
                ans = max(ans, events[i][2]);
            } else {
                auto nxt = pq.top();
                ans = max(ans, events[i][2] + nxt.first);
            }
        }
        return ans;
    }
};

// Brute Force, sort by starttime, pick 0 ~ n one and find the larget time by endtime  ~the end
// 
