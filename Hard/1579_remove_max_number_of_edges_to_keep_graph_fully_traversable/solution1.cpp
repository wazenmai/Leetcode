/**
 * Title:  Remove Max Number of Edges to Keep Graph Fully Traversable (Leetcode Hard 1579)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, June, 2024
 * Method: Use UnionSet to check connectivity of Alice and Bob, and traverse both, Alice, Bob edges to check if they are connected.
 * Result: Time complexity is O(E), space complexity is O(E).
 */

class UnionSet {
private:
    vector<int> rank;
    vector<int> parent;
public:
    UnionSet(int n) {
        parent.resize(n, 0);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int check(int x) {
        if (parent[x] == x) return x;
        return parent[x] = check(parent[x]);
    }
    void join(int x, int y) {
        int px = check(x);
        int py = check(y);
        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else if (rank[py] > rank[px]) {
            parent[px] = py;
        } else {
            rank[px]++;
            parent[py] = px;
        }
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(3);
        int a = 0;
        int b = 0;
        int both = 0;
        for (auto& e: edges) {
            if (e[0] == 1) a++;
            else if (e[0] == 2) b++;
            else both++;
            graph[e[0] - 1].emplace_back(make_pair(e[1] - 1, e[2] - 1));
        }

        UnionSet alice = UnionSet(n);
        UnionSet bob = UnionSet(n);
        // traverse both
        for (auto& p: graph[2]) {
            if (alice.check(p.first) != alice.check(p.second)) {
                alice.join(p.first, p.second);
                bob.join(p.first, p.second);
                both--;
            }
        }
        // traverse alice
        for (auto& p: graph[0]) {
            if (alice.check(p.first) != alice.check(p.second)) {
                alice.join(p.first, p.second);
                a--;
            }
        }
        // traverse bob
        for (auto& p: graph[1]) {
            if (bob.check(p.first) != bob.check(p.second)) {
                bob.join(p.first, p.second);
                b--;
            }
        }
        // check connectivity
        // cout << a << " " << b << " " << both << "\n";
        for (int i = 1; i < n; i++) {
            if (alice.check(i) != alice.check(i - 1)) return -1;
            if (bob.check(i) != bob.check(i - 1)) return -1;
        }
        return a + b + both;
    }
};
