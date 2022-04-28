/**
 * Title:  Path with minimum effort (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, April, 2022
 * Method: Dijkstra algorithm. Maintain minEffort array to record the min effort, use priority queue to get min effort.
 */

class Solution {
public:
    int dc[4] = {0, 0, -1, 1};
    int dr[4] = {-1, 1, 0, 0};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = (int)heights.size();
        int cols = (int)heights[0].size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> effort(rows, vector<int>(cols, 1000000));
        effort[0][0] = 0;
        pq.push({0,0,0});
        
        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();
            if (effort[v[1]][v[2]] < v[0])
                continue;
            if (v[1] == rows - 1 && v[2] == cols - 1)
                return v[0];
            for (int d = 0; d < 4; d++) {
                int nr = v[1] + dr[d];
                int nc = v[2] + dc[d];
                if (nr < 0 || nr == rows)
                    continue;
                if (nc < 0 || nc == cols)
                    continue;
                int dis = max(v[0], abs(heights[v[1]][v[2]] - heights[nr][nc]));
                if (effort[nr][nc] <= dis)
                    continue;
                effort[nr][nc] = dis;
                pq.push({dis, nr, nc});
            }
        }
        return 0;
    }
};