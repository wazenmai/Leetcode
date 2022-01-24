/**
 * Title:  Redundant Connection II (Leetcode Hard 685)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, May, 2021
 * Method: Graph, UnionSet
 */

class Solution {
private:
    vector<int> us;
    vector<int> parent;
    int findSet(int x) {
        if (us[x] == 0)
            return x;
        return (us[x] = findSet(us[x]));
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = (int)edges.size();
        us.resize(n, 0);
        parent.resize(n, 0);
        
        for (auto& e : edges) {
            if (parent[e[1]] == -1) {
                parent[e[1]] = e[0];
                int fx = findSet(e[0]);
                int fy = findSet(e[1]);
                if (fx != fy) {
                    us[fx] = fy;
                } else {
                    
                }
            } else {

            }
        }
        
        us.clear();
    }
};
