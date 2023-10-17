/**
 * Title:  Validate Binary Tree Nodes (Leetcode Medium 1361)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, October, 2023
 * Method: Union Find to check whether there is a cycle, use visit vector to check whether two nodes have same child
 * Result: Time complexity O(n), Space complexity O(n)
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
        if (parent[x] != x)
            return find(parent[x]);
        return x;
    }

    bool merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return false;
        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else if (rank[px] == rank[py]){
            parent[py] = px;
            rank[px]++;
        } else {
            parent[px] = py;
        }
        return true;
    }
};
// 0 1 0 0 (rank)
// 1 1 1 3 (parent)
// 0 1 2 3  (x)

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        UnionFind us = UnionFind(n);
        vector<bool> visit(n, false);
        for (int i = 0; i < n; i++) {
            // cout << "node " << i << "\n";
            if (leftChild[i] != -1) {
                if (visit[leftChild[i]]) return false;
                if (!us.merge(i, leftChild[i])) return false;
                visit[leftChild[i]] = true;
            }
            if (rightChild[i] != -1) {
                if (visit[rightChild[i]]) return false;
                if (!us.merge(i, rightChild[i])) return false;
                visit[rightChild[i]] = true;
            }
        }
        // Check whether on the same tree
        int p = us.find(0);
        for (int i = 1; i < n; i++)
            if (us.find(i) != p)
                return false;
        return true;
    }
};