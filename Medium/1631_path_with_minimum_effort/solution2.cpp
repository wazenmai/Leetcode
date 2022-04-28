/**
 * Title:  Path with minimum effort (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, April, 2022
 * Method: Binary search find answer, bfs the graph. (logK * N^2)
 */

class Solution {
private:
    int rows;
    int cols;
public:
    int dc[4] = {0, 0, -1, 1};
    int dr[4] = {-1, 1, 0, 0};
    
    bool check(vector<vector<int>>& heights, int k) {
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        
        q.push(make_pair(0, 0));
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto v = q.front();
            // cout << "  take " << v.first << " " << v.second << endl;
            if (v.first == rows - 1 && v.second == cols - 1)
                return true;
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = v.first + dr[d];
                int nc = v.second + dc[d];
                if (nr < 0 || nr == rows)
                    continue;
                if (nc < 0 || nc == cols)
                    continue;
                if (visited[nr][nc])
                    continue;
                if (abs(heights[v.first][v.second] - heights[nr][nc]) > k)
                    continue;
                visited[nr][nc] = true;
                q.push(make_pair(nr, nc));
            }
        }
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        rows = (int)heights.size();
        cols = (int)heights[0].size();
        int inf = 1000000;
        
        // cout << rows << " " << cols << endl;
        
        if (rows == 1 && cols == 1)
            return 0;
        
        int l = 0;
        int r = 1000000;
        int ans = 1000000;
        while (l < r) {
            int mid = (l + r) / 2;
            // cout << "check " << mid << endl;
            if (check(heights, mid)) {
                r = mid;
                ans = min(ans, mid);
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
