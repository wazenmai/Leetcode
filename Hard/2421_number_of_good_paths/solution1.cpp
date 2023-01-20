/**
 * Title:  Number of Good Paths (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, Janurary, 2023
 * Note:   This is daily challenge 15, Janurary.
 */

class UnionSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return (parent[x] = find(parent[x]));
    }

    void union_find(int x, int y) {
        int xset = find(x);
        int yset = find(y);
        if (xset == yset) {
            return;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else if (rank[yset] > rank[xset]) {
            parent[xset] = yset;
        } else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> graph(n);
        map<int, vector<int>> m;      // values map
        UnionSet us = UnionSet(n);     // connected component
        int ans = 0;
        for (auto& e: edges) {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }
        for (int i = 0; i < n; i++) {
            m[vals[i]].emplace_back(i);
        }

        for (auto& [val, nodes]: m) {
            for (int node: nodes) {
                for (int nb: graph[node]) {
                    // visit all neighbors and use union to make connected component
                    if (vals[node] >= vals[nb]) {
                        us.union_find(node, nb);
                    }
                }
            }
            unordered_map<int, int> group;
            for (int node: nodes) {
                group[us.find(node)]++;
            }
            for (auto& [g, size]: group) {
                ans += (size * (size + 1) / 2);
            }
        }
        return ans;
    }
};