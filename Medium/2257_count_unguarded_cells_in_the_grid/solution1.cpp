/**
 * Title:  Count Unguarded Cells in the Grid (Leetcode Medium 2257)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, November, 2024
 * Method: First put wall and guard on the graph, then iterate through all guards and mark the cells that are guarded by the guard, if the cell is not guarded, then decrease the answer by 1.
 * Result: Time complexity O(g(m + n)), Space complexity O(mn). // g is the number of guards, m is the number of rows, n is the number of columns.
 */

class Solution {
private:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> graph(m, vector<int>(n, 0));
        // 0: green, 1: red, 2: wall, 3: guard
        for (auto& wall: walls) {
            graph[wall[0]][wall[1]] = 2;
        }
        for (auto& guard: guards) {
            graph[guard[0]][guard[1]] = 3;
        }
        int ans = m * n - walls.size() - guards.size();
        for (auto& guard: guards) {
            for (int d = 0; d < 4; d++) {
                int y = guard[0] + dy[d];
                int x = guard[1] + dx[d];
                while (y >= 0 && y < m && x >= 0 && x < n) {
                    if (graph[y][x] == 2 || graph[y][x] == 3) break;
                    if (graph[y][x] == 0) {
                        ans--;
                        graph[y][x] = 1;
                    }
                    y += dy[d];
                    x += dx[d];
                }
            }
            // cout << "guard: (" << guard[0] << "," << guard[1] << "): " << ans << "\n";
        }
        return ans;
    }
};
