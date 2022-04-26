/**
 * Title:  Min Cost to Connect All Points (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, April, 2022
 * Method: Kruskal’s Minimum Spanning Tree using Union-find and path comparession. Stop the loop when we select V-1 edges.
 */

struct compare {
    bool operator() (const vector<int>& a, const vector<int>& b) {
        return a[0] > b[0];
    }
};

class Solution {
private:
    priority_queue<vector<int>, vector<vector<int>>, compare> heap;
public:
    int find(vector<int>& parent, int i) {
        if (parent[i] != i)
            return (parent[i] = find(parent, parent[i]));
        return parent[i];
    }
    
    void Union(vector<int>& parent, int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        parent[xset] = yset;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                heap.push(vector<int>{w, i, j});
            }
        }
        
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            v[i] = i;
        
        int ans = 0;
        int selected = n - 1;
        while (!heap.empty() && selected) {
            auto w = heap.top();
            if (find(v, w[1]) != find(v, w[2])) {
                // cout << w[1] << " -> " << w[2] << ": " << w[0] << "\n";
                selected--;
                ans += w[0];
                Union(v, w[1], w[2]);
            }
            heap.pop();
        }
        return ans;
    }
};
