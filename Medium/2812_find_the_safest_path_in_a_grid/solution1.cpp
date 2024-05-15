/**
 * Title:  Maximum Odd Binary Number (Leetcode Easy 2864)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, May, 2024
 * Method: Collect idx of thiefs, and use binary search to find the maximum safe distance, for each distance, use bfs to check path is available or not.
    * Each block will pass to isSafe function to check if the block is safe or not.
 * Result: TLE. Time complexity O(n^2 + logn * n^2 * n^2) = O(n^4logn). Space complexity O(n^2).
 */

class Solution {
private:
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
    int n;
public:
    bool isSafe(const vector<pair<int, int>>& thiefs, int i, int j, int safe) {
        for (auto& thief: thiefs) {
            int dist = abs(thief.first - i) + abs(thief.second - j);
            if (dist < safe) return false;
        }
        return true;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        if ((grid[0][0] == 1) || (grid[n - 1][n - 1] == 1)) return 0;
        // cout << "n=" << n << "\n";
        // 0. Collect block (i, j) with thief
        vector<pair<int, int>> thiefs;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    thiefs.emplace_back(make_pair(i, j));
            }
        }

        int l = 0, r = n + n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            cout << "check " << mid << ": (" << l << "," << r << ")\n";
            vector<vector<bool>> visit(n, vector<bool>(n, false));
            queue<pair<int, int>> q;
            // 1. Check start and goal is available or not
            if (!isSafe(thiefs, 0, 0, mid) || !isSafe(thiefs, n - 1, n - 1, mid)) {
                r = mid;
                continue;
            }
            q.push(make_pair(0, 0));
            visit[0][0] = true;
            bool goal = false;
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int ni = cur.first + di[d];
                    int nj = cur.second + dj[d];
                    if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
                    if (visit[ni][nj]) continue;
                    if (ni == n - 1 && nj == n - 1) {
                        goal = true;
                        break;
                    }
                    if (isSafe(thiefs, ni, nj, mid)) {
                        q.push(make_pair(ni, nj));
                        visit[ni][nj] = true;
                    } else {
                        visit[ni][nj] = true;
                    }
                }
                if (goal) break;
            }

            if (goal) {
                if (l == mid) return l;
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
