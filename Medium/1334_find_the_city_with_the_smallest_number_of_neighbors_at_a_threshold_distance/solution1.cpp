/**
 * Title:  Find the City with the Smallest Number of Neighbors at a Threshold Distance(Leetcode Medium 1334)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, May, 2021
 * Method: Graph, Floyd Warshall
 */

class Solution {
private:
    int g[105][105];
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // construct the graph
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = 0x3f3f3f3f;
        for (auto& e : edges) {
            g[e[0]][e[1]] = e[2];
            g[e[1]][e[0]] = e[2];
        }

        // Floyd Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (g[i][j] > g[i][k] + g[k][j]) {
                        g[i][j] = g[i][k] + g[k][j];
                    }
                }
            }
        }

        // Find the city with the smallest number of neighbors at a threshold distance
        int sum = 0;
        int ans = 0x3f3f3f3f;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = 0; j < n; j++) {
                if (j == i)
                    continue;
                if (g[i][j] <= distanceThreshold)
                    sum += 1;
            }
            if (sum <= ans) {
                ans = sum;
                idx = i;
            }
        }
        return idx;
    }
};
