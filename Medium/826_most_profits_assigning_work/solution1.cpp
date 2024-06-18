/**
 * Title:  Most Profit Assigning Work (Leetcode Medium 826)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, June, 2024
 * Result: Time complexity is O(nlogn + mlogm), space complexity is O(n + m).
 */

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = worker.size();
        int m = profit.size();
        vector<pair<int, int>> job(m);
        for (int i = 0; i < m; i++) {
            job[i] = make_pair(difficulty[i], profit[i]);
        }
        sort(worker.begin(), worker.end());
        sort(job.begin(), job.end());
        int ans = 0;
        int j = 0;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            while (j < m && job[j].first <= worker[i]) {
                pq.push(job[j].second);
                j++;
            }
            if (!pq.empty())
                ans += pq.top();
            // cout << worker[i] << " " << ans << "\n";
        }
        return ans;
    }
};
