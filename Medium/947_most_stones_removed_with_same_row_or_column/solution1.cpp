/**
 * Title:  Most Stones Removed with Same Row or Column (Leetcode Medium 947)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, August, 2024
 * Method: UnionFind. Merge stones with same row or column, then count the number of connected components.
 * Result: Time complexity is O(n^2), space complexity is O(n).
 */

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else if (rank[py] > rank[px]) {
            parent[px] = py;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        if (n == 1) return 0;
        UnionFind uf = UnionFind(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    uf.merge(i, j);
                }
            }
        }
        unordered_set<int> us;
        for (int i = 0; i < n; i++) {
            us.insert(uf.find(i));
        }
        return n - us.size();
    }
};
