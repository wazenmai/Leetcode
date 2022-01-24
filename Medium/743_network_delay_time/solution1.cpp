/**
 * Title:  Network Delay Time (Leetcode Medium 743)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, Apr, 2021
 */

class Solution {
private:
    int g[105][105];
    int d[105];
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = -1;
            }
        }
        for (auto v : times) {
           g[v[0]][v[1]] = v[2];
        }
        for (int i = 1; i <= n; i++)
            d[i] = 0x3f3f3f3f;
    
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(pair{0, k});
        d[k] = 0;
        int node, dist;
        while (!pq.empty()) {
            dist = pq.top().first;
            node = pq.top().second;
            pq.pop();
            if (d[node] >= dist) {
                for (int i = 1; i <= n; i++) {
                    if (g[node][i] != -1 && (dist + g[node][i] < d[i])) {
                        d[i] = dist + g[node][i];
                        pq.push(pair{d[i], i});
                    }
                }
            }
        }
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            if (d[i] == 0x3f3f3f3f) {
                ans = -1;
                break;
            }
            ans = max(d[i], ans);
        }
        return ans;
    }
};