/**
 * Title:    Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree (Leetcode Hard)
 * Author:   Bronwin Chen <iotbwu0101@gmail.com>
 * Date:     19, August, 2023
 * Method:   Sort edge. Construct MST. Iterate through all edges to see whether it is critical or pseudo-critical.
 * Analysis: Time Complexity O(m^2). Space complexity O(m).
 */

class UnionSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionSet() {}
    UnionSet(int n) {
        rank.resize(n, 1);
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
        if (xset == yset)
            return;
        if (rank[yset] > rank[xset]) {
            parent[xset] = yset;
            rank[yset] += rank[xset];
        } else {
            parent[yset] = xset;
            rank[xset] += rank[yset];
        }
    }
    int get_size() {
        return rank[find(0)];
    }
};

class Solution {
private:
    UnionSet us;
    vector<int> count;
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }
    void printEdge(vector<vector<int>>& edges) {
        for (auto edge: edges) {
            cout << edge[3] << ".(" << edge[0] << "," << edge[1] << "): " << edge[2] << "\n";
        }
        cout << "\n";
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // Step 1. Create new version of edges with index
        int e = edges.size();
        vector<vector<int>> new_edges = edges;
        for (int i = 0; i < e; i++) {
            new_edges[i].emplace_back(i);
        }
        sort(new_edges.begin(), new_edges.end(), compare);
        printEdge(new_edges);
       
        // Find a mst tree
        us = UnionSet(n);
        int mstWeight = 0;
        for (auto edge: new_edges) {
            if (us.find(edge[0]) != us.find(edge[1])) {
                cout << "(" << edge[0] << "," << edge[1] << ") ";
                mstWeight += edge[2];
                us.union_find(edge[0], edge[1]);
            }
        }
        cout << mstWeight << "\n";

        vector<int> critical, pseudo;
        for (int i = 0; i < e; i++) {
            // exclude new_edges[i]
            UnionSet tempUS = UnionSet(n);
            int tempWeight = 0;
            for (int j = 0 ; j < e; j++) {
                auto edge = new_edges[j];
                if (i != j && (tempUS.find(edge[0]) != tempUS.find(edge[1]))) {
                    tempWeight += edge[2];
                    tempUS.union_find(edge[0], edge[1]);
                }
            }
            if (tempUS.get_size() != n || tempWeight > mstWeight) {
                // critical: deletion cause weight to increase or st disappear
                critical.emplace_back(new_edges[i][3]);
            } else {
                // pseudo-critical: can appear in mst
                UnionSet newUS = UnionSet(n);
                int newWeight = new_edges[i][2];
                newUS.union_find(new_edges[i][0], new_edges[i][1]);
                for (int j = 0 ; j < e; j++) {
                    auto edge = new_edges[j];
                    if (i != j && (newUS.find(edge[0]) != newUS.find(edge[1]))) {
                        newWeight += edge[2];
                        newUS.union_find(edge[0], edge[1]);
                    }
                }
                if (newWeight == mstWeight)
                    pseudo.emplace_back(new_edges[i][3]);
            }
        }
        return {critical, pseudo};
    }
};

// spanning tree:         edges that connect all nodes without forming circle
// minimum spanning tree: minimum weights of spanning tree
// critical edge:         deletional cause weight to increase or st disappear
// pseudo-critical edge:  can appear in mst
// Algorithm for spanning tree: Kruskal's algorithm
/*
Time complexity: 
    - Sorting edges: O(mlogm)
    - Construct MST: O(m) = O(m.alpha(n))
    - Iterating through all edges: O(m^2) = O(m^2.alpha(n))
Space complexity: O(m + n) = O(m)
*/
