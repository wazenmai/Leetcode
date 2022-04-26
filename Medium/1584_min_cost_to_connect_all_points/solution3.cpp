/**
 * Title:  Min Cost to Connect All Points (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, April, 2022
 * Method: Kruskal’s Minimum Spanning Tree using Union-find. Change heap to vector + sort.
 */

bool compare (const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

class Solution {
private:
    vector<vector<int>> v;
public:
    int find(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
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
                v.emplace_back(vector<int>{w, i, j});
            }
        }
        
        sort(v.begin(), v.end(), compare);
        
        vector<int> parent(n, -1);
        int ans = 0;
        int selected = n - 1;
        for (auto& w: v) {
            if (!selected)
                break;
            if (find(parent, w[1]) != find(parent, w[2])) {
                // cout << w[1] << " -> " << w[2] << ": " << w[0] << "\n";
                selected--;
                ans += w[0];
                Union(parent, w[1], w[2]);
            }
        }
        return ans;
    }
};
