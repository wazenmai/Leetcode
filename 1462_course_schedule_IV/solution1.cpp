/**
 * Title:  Course Schedule IV (Leetcode Medium 1462)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, May, 2021
 * Method: Graph, Floyd Warshall
 */

#define MAXN 0x3f3f3f3f

class Solution {
private:
    int g[105][105];
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // construct graph
        for (int i = 0; i < numCourses; i++)
            for (int j = 0; j < numCourses; j++)
                g[i][j] = MAXN;
        for (auto& p : prerequisites) {
            g[p[0]][p[1]] = 1;
        }

        // Floyd Warshall
        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {
                    if (g[i][j] > g[i][k] + g[k][j])
                        g[i][j] = g[i][k] + g[k][j];
                }
            }
        }

        vector<bool> ans;
        for (auto& q : queries) {
            ans.emplace_back((g[q[0]][q[1]] != MAXN) ? true : false);
        }
        return ans;
    }
};

