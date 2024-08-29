/**
 * Title:  Count Sub Islands (Leetcode Medium 1905)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, August, 2024
 * Method: DFS. 
 * Result: Time complexity is O(n * m), space complexity is O(1).
 */

class Solution {
private:
    int n;
    int m;
public:
    int dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m) return true;
        if (grid2[i][j] == 0) return true;
        if (grid2[i][j] == 1 && grid1[i][j] == 0) return false;
        grid1[i][j] = 0; // visited
        grid2[i][j] = 0;
        bool up = dfs(grid1, grid2, i - 1, j);
        bool down = dfs(grid1, grid2, i + 1, j);
        bool left = dfs(grid1, grid2, i, j - 1);
        bool right = dfs(grid1, grid2, i, j + 1);
        return (up && down && left && right);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size();
        m = grid1[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid1[i][j] == 1 && grid2[i][j] == 1) {
                    ans += dfs(grid1, grid2, i, j);
                }
            }
        }
        return ans;
    }
};
