/**
 * Title:  Path with minimum effort (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, September, 2023
 * Method: Dijkstra algorithm. Maintain minEffort array to record the min effort, use priority queue to get min effort. Time complexity O(nlogn)
 */

class Solution {
private:
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    struct my_comparator {
        bool operator()(vector<int> const& a, vector<int> const& b) const {
            // reverse sort puts the lowest value at the top    
            return a[2] > b[2];
        }
    };
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        // cout << rows << " " << cols << "\n";
        vector<vector<int>> dis(rows, vector<int>(cols, 1e6));
        vector<vector<bool>> book(rows, vector<bool>(cols, false)); // known point
        priority_queue<vector<int>, vector<vector<int>>, my_comparator> pq;
        dis[0][0] = 0; // distance from (0, 0) to (0, 0)
        pq.push(vector<int>{0, 0, 0});
        int count = rows * cols;
        for (int v = 0; v < count; v++) {
            auto u = pq.top();
            pq.pop();
            while (book[u[0]][u[1]]) {
                u = pq.top();
                pq.pop();
            }
            book[u[0]][u[1]] = true;
            // cout << i << ". pick (" << u[0] << "," << u[1] << "): " << u[2] << "\n";
            for (int d = 0; d < 4; d++) {
                int nr = u[0] + dr[d];
                int nc = u[1] + dc[d];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols)
                    continue;
                // cout << "  " << nr << ", " << nc << ": " << book[nr][nc] << "\n";
                if (!book[nr][nc]) {
                    int effort = abs(heights[nr][nc] - heights[u[0]][u[1]]);
                    dis[nr][nc] = min(dis[nr][nc], max(u[2], effort));
                    pq.push(vector<int>{nr, nc, dis[nr][nc]});
                    // cout << "release (" << nr << "," << nc << "): " << dis[nr][nc] << "\n";
                }

            }
        }
        // cout << "ans: " << dis[rows - 1][cols - 1] << "\n\n";
        return dis[rows - 1][cols - 1];
    }
};
