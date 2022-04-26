/**
 * Title:  Min Cost to Connect All Points (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, April, 2022
 * Method: Prim’s Minimum Spanning Tree using minDist array.
 */

class Solution {
public:    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        
        vector<bool> v(n, false); // inMST
        vector<int> d(n, INT_MAX); // minDist
        d[0] = 0;
        int selected_edge = 0;
        int ans = 0;
        
        while (selected_edge < n) {
            int min = INT_MAX;
            int node = -1;
            
            for (int i = 0; i < n; i++) {
                if (!v[i] && d[i] < min) {
                    min = d[i];
                    node = i;
                }
            }
            
            ans += min;
            selected_edge++;
            // cout << node << ": " << min << endl;
            v[node] = true;
            
            for (int i = 0; i < n; i++) {
                int w = abs(points[i][0] - points[node][0]) + abs(points[i][1] - points[node][1]);
                if (!v[i] && d[i] > w) {
                    d[i] = w;
                }
            }
        }
        return ans;
    }
};
