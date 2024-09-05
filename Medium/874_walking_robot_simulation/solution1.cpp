/**
 * Title:  Walking Robot Simulation (Leetcode Medium 874)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, September, 2024
 */

class Solution {
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> us;
        for (auto& ob: obstacles) {
            us.insert(make_pair(ob[0], ob[1]));
        }
        int x = 0, y = 0;
        int dir = 0;
        int ans = 0;
        for (int& com: commands) {
            if (com == -2) {
                dir = (dir + 3) % 4;
            } else if (com == -1) {
                dir = (dir + 1) % 4;
            } else {
                for (int i = 1; i <= com; i++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (us.find(make_pair(nx, ny)) != us.end()) {
                        break;
                    }
                    x = nx;
                    y = ny;
                }
                ans = max(ans, x * x + y * y);
            }
            // cout << com << ": (" << x << "," << y << ")\n";
        }
        return ans;
    }
};

