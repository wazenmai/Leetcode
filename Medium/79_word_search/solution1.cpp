/**
 * Title:  Word Search (Leetcode Easy 79)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, April, 2024
 * Method: Traverse the board and find the first character of the word. Then use DFS to find the word.
 * Result: Time complexity is O(n^2 * m^2), space complexity is O(n*m).
 */

class Solution {
private:
    int di[4] = {0, 0, -1, 1};
    int dj[4] = {-1, 1, 0, 0};
    int n;
    int m;
public:
    bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& visit, int i, int j, string& temp) {
        temp += board[i][j];
        visit[i][j] = true;
        // cout << "dfs (" << i << "," << j << "): " << temp << "\n";
        if (word == temp) return true;
        for (int d = 0; d < 4; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];
            // cout << "check d" << d << ":(" << ni << "," << nj << "), ";
            if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
            if (visit[ni][nj]) continue;
            if (board[ni][nj] == word[temp.length()]) {
                if (dfs(board, word, visit, ni, nj, temp)) return true;
                temp.pop_back();
                visit[ni][nj] = false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        string empty_s = "";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (word.length() == 1) return true;
                    vector<vector<bool>> visit(n, vector<bool>(m, false));
                    string temp = "";
                    if (dfs(board, word, visit, i, j, temp)) return true;
                }
            }
        }
        return false;
    }
};
// ABCESEEEFS"

// [["A","B","C","E"],
//  ["S","F","E","S"],[
//   "A","D","E","E"]]
