/**
 * Title:  Sliding Puzzle (Leetcode Hard 773)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, November, 2024
 * Method: Encode the board as a string to record visisted status. Use BFS to search the shortest path that can reach the target board.
 * Result: Time complexity is O((mn)! * mn). Space complexity O((mn)!). Since there are (mn)! possible board status, and for each status we will check whether it is target board or not.
 */

class Solution {
private:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
public:
    bool check(vector<vector<int>>& board) {
        if (board[0][0] == 1 && board[0][1] == 2 && board[0][2] == 3 && board[1][0] == 4 && board[1][1] == 5) return true;
        return false;
    }
    void print(vector<vector<int>>& board) {
        for (auto& b: board) {
            for (auto& e: b) {
                cout << e << " ";
            }
            cout << "\n";
        }
    }
    string encode(vector<vector<int>>& board) {
        string s = "";
        char idx = '0';
        for (auto& b: board) {
            for (auto& e: b) {
                char c = '0' + e;
                s += (idx + c);
                idx++;
            }
        }
        return s;
    }
    int slidingPuzzle(vector<vector<int>> board) {
        if (check(board)) return 0;
        int n = board.size(), m = board[0].size();
        queue<pair<vector<int>, vector<vector<int>>>> q;
        int pos_0, pos_1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0) {
                    pos_0 = i;
                    pos_1 = j;
                    break;
                }
            }
        }
        unordered_set<string> us;
        q.push(make_pair(vector<int>{pos_0, pos_1}, board));
        us.insert(encode(board));
        int step = 0;
        while (!q.empty()) {
            step++;
            int s = q.size();
            for (int k = 0; k < s; k++) {
                auto [pos, b] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int ni = pos[0] + dy[d];
                    int nj = pos[1] + dx[d];
                    if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                    auto nb = b;
                    nb[pos[0]][pos[1]] = b[ni][nj];
                    nb[ni][nj] = b[pos[0]][pos[1]];
                    if (check(nb)) return step;
                    auto enc = encode(nb);
                    if (us.find(enc) != us.end()) continue;
                    q.push(make_pair(vector<int>{ni, nj}, nb));
                    us.insert(enc);
                }
            }
            if (step > 30) break;
        }
        return -1;
    }
};
