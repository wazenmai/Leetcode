/**
 * Title:  Jump Game IV (Leetcode Hard 1345)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, Jan, 2022
 * Method: Build graph, then bfs
 * Result: TLE
 */

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        cout << "size: " << n << "\n";
        if (n == 1)
            return 0;
        
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i-1; j++) {
                if (arr[j] == arr[i])
                    graph[i].emplace_back(j);
            }
            if (i > 0)
                graph[i].emplace_back(i-1);
            if (i < n - 1)
                graph[i].emplace_back(i+1);
            
            for (int j = i+2; j < n; j++) {
                if (arr[j] == arr[i])
                    graph[i].emplace_back(j);
            }
        }
        
        // for (int i = 0; i < n; i++) {
        //     cout << arr[i] << ": ";
        //     int m = graph[i].size();
        //     for (int j = 0; j < m; j++) {
        //         cout << graph[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        
        vector<bool> visit(n, false);
        queue<pair<int, int>> q;
        int ans = n - 1;
        q.push(make_pair(0, 0));
        visit[0] = true;
        // cout << "===BFS===\n";
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            // cout << v.first << " " << v.second << "\n";
            if (v.first == n - 1) {
                ans = v.second;
                break;
            }
            for (auto& id: graph[v.first]) {
                if (!visit[id]) {
                    visit[id] = true;
                    q.push(make_pair(id, v.second + 1));
                }
            }
        }
        return ans;
    }
};
