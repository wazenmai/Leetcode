/**
 * Title:  Maximum Average Pass Ratio (Leetcode Medium 1792)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, December, 2024
 * Method: Use priority_queue to find the max difference between original value and +1+1 value.
 * Result: Time complexity is O(nlogn), space complexity is O(n). n is the number of classes.
 */

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, const int extraStudents) {
        priority_queue<pair<double, size_t>> pq; // the difference between original value and +1+1value
        const size_t n = classes.size();
        for (size_t i = 0; i < n; i++) {
            double org = (double)classes[i][0] / classes[i][1];
            double nxt = ((double)classes[i][0] + 1) / (classes[i][1] + 1);
            pq.push(make_pair(nxt - org, i));
        }
        for (int i = 0; i < extraStudents; i++) {
            auto [v, id] = pq.top();
            pq.pop();
            classes[id][0]++;
            classes[id][1]++;
            // cout << id << "," << v << ": " << classes[id][0] << "," << classes[id][1] << "\n";
            double org = (double)classes[id][0] / classes[id][1];
            double nxt = ((double)classes[id][0] + 1) / (classes[id][1] + 1);
            pq.push(make_pair(nxt - org, id));
        }
        double ans = 0;
        while (!pq.empty()) {
            ans += (double)classes[pq.top().second][0] / classes[pq.top().second][1];
            pq.pop();
        }
        return ans / n;
    }
};
