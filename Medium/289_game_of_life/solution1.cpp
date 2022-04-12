/**
 * Title:  Game of Life (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, April, 2022
 */

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = (int)board.size(), n = (int)board[0].size();
        int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<vector<int>> lives(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int d = 0; d < 8; d++) {
                    if (i + dy[d] < 0 || i + dy[d] >= m) continue;
                    if (j + dx[d] < 0 || j + dx[d] >= n) continue;
                    lives[i][j] += board[i + dy[d]][j + dx[d]];
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0)
                    board[i][j] = (lives[i][j] == 3) ? 1 : 0;
                else
                    board[i][j] = (lives[i][j] == 2 || lives[i][j] == 3) ? 1 : 0;
            }
        }
    }
};
