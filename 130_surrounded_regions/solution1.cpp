/**
 * Title:  Surrounded Regions (Leetcode Medium 130)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, Mar, 2021
 */

class Solution {
private:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int r_size, c_size;
    queue<pair<int, int>> q;
    void dfs(vector<vector<char>>& board, int r, int c) {
        for (int j = 0; j < 4; j++) {
            int newx = c + dx[j];
            int newy = r + dy[j];
            if (newx >= 0 && newx < c_size &&
                newy >= 0 && newy < r_size &&
                board[newy][newx] == 'O') {
                    board[newy][newx] = '$';
                    dfs(board, newy, newx);
                }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        // handle boundary
        r_size = board.size();
        c_size = board[0].size();
        for (int i = 0; i < r_size; i++) {
            if (board[i][0] == 'O') {
                board[i][0] = '$';
                q.push(make_pair(i, 0));
            }
            if (board[i][c_size - 1] == 'O') {
                board[i][c_size - 1] = '$';
                q.push(make_pair(i, c_size - 1));
            }
        }
        for (int i = 0; i < c_size; i++) {
            if (board[0][i] == 'O') {
                board[0][i] = '$';
                q.push(make_pair(0, i));
            }
            if (board[r_size - 1][i] == 'O') {
                board[r_size - 1][i] = '$';
                q.push(make_pair(r_size - 1, i));
            }
        }

        int qs = q.size();
        while (qs--) {
            dfs(board, q.front().first, q.front().second);
            q.pop();
        } 

        // run through graph, '$' -> 'O', 'O' -> 'X'
        for (int i = 0; i < r_size; i++) {
            for (int j = 0; j < c_size; j++) {
                if (board[i][j] == '$')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }   
    }
};