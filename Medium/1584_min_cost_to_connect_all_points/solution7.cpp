/**
 * Title:  Min Cost to Connect All Points (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, September, 2023
 * Method: Kruskal’s Minimum Spanning Tree using Union-find and path comparession. Stop the loop when we select V-1 edges.
 */

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        rank.resize(n, 0);
    }
    int find(int x) {
        if (x == parent[x])
            return x;
        return find(parent[x]);
    }
    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else if (rank[px] < rank[py]){
            parent[px] = py;
        } else {
            rank[px]++;
            parent[py] = px;
        }
    }
};

class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
    void printvec(vector<vector<int>>& v) {
        for (auto& e: v) {
            cout << "(" << e[0] << "," << e[1] << "): " << e[2] << "\n";
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges; // (p1, p2, distance)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.emplace_back(vector<int>{i, j, dis});
            }
        }
        sort(edges.begin(), edges.end(), compare);
        // printvec(edges);
        UnionFind u = UnionFind(n);
        int ans = 0;
        int use_edge = 0;
        for (auto& edge: edges) {
            if (u.find(edge[0]) != u.find(edge[1])) {
                // cout << "merge " << edge[0] << " " << edge[1] << ": " << edge[2] << "\n";
                u.merge(edge[0], edge[1]);
                // cout << " " << edge[0] << ": " << u.find(edge[0]) << ", " << edge[1] << ": " << u.find(edge[1]) << "\n";
                ans += edge[2];
                ++use_edge;
            }
            if (use_edge == n - 1)
                break;
        }
        return ans;
    }
};
