/**
 * Title:  Jump Game IV (Leetcode Hard 1345)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, Jan, 2022
 * Method: Erase used value map can reduce running time.
 * Result: Accepted
 */

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        // cout << "size: " << n << "\n";
        if (n == 1)
            return 0;
        
        // make same value graph
        map<int, vector<int>> graph;
        for (int i = 0; i < n; i++) {
            graph[arr[i]].emplace_back(i);
        }
        
        vector<bool> visit(n, false);
        queue<pair<int, int>> q;
        int ans = n - 1;
        q.push(make_pair(0, 0));
        visit[0] = true;
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            if (v.first == n - 1) {
                ans = v.second;
                break;
            }
            if (v.first > 0 && !visit[v.first-1]) {
                q.push(make_pair(v.first-1, v.second+1));
                visit[v.first-1] = true;
            }
            if (v.first < n - 1 && !visit[v.first+1]) {
                q.push(make_pair(v.first+1, v.second+1));
                visit[v.first+1] = true;
            }
            if (!graph.count(arr[v.first]))
                continue;
            for (auto& u : graph[arr[v.first]]) {
                if (!visit[u]) {
                    q.push(make_pair(u, v.second + 1));
                    visit[u] = true;
                }
            }
            graph.erase(arr[v.first]);
        }
        return ans;
        
    }
};
