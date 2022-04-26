/**
 * Title:  Min Cost to Connect All Points (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, April, 2022
 * Method: Prim’s Minimum Spanning Tree using min-heap.
 */

struct compare {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
};

class Solution {
private:
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> p;
public:    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        
        vector<bool> v(n, false);
        int select_node = n;
        
        p.push(make_pair(0, 0));
        int ans = 0;
        while (!p.empty() && select_node) {
            auto node = p.top();
            p.pop();
            if (v[node.second])
                continue;
            
            select_node--;
            v[node.second] = true;
            ans += node.first;
            
            for (int i = 0; i < n; i++) {
                if (i == node.second)
                    continue;
                int edge = abs(points[node.second][0] - points[i][0]) + abs(points[node.second][1] - points[i][1]);
                p.push(make_pair(edge, i));
            }
        }
        return ans;
    }
};
