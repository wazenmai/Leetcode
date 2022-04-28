/**
 * Title:  Path with minimum effort (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, April, 2022
 * Method: BFS and sort the maximum path.
 * Result: TLE.  O(N^2logN)
 */

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = (int)heights.size();
        int cols = (int)heights[0].size();
        
        cout << rows << " " << cols << endl;
        
        if (rows == 1 && cols == 1)
            return 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push(vector<int>{0, 0, 0});
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};
        
        while (!pq.empty()) {
            auto v = pq.top();
            visited[v[1]][v[2]] = true;
            if (v[1] == rows - 1 && v[2] == cols - 1) {
                return v[0];
            }
            pq.pop();
            // cout << "(" << v[1] << ", " << v[2] << "): " << v[0] << endl;
            for (int d = 0; d < 4; d++) {
                int ny = v[1] + dy[d];
                int nx = v[2] + dx[d];
                if (ny < 0 || ny >= rows)
                    continue;
                if (nx < 0 || nx >= cols)
                    continue;
                if (!visited[ny][nx]) {
                    int dis = max(v[0], abs(heights[v[1]][v[2]] - heights[ny][nx]));
                    pq.push(vector<int>{dis, ny, nx});
                }
            }
        }
    }
};
