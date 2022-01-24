/**
 * Title:  Evaluation Division (Leetcode Medium 399)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, Apr, 2021
 * Method: Graph, dfs
 */

class Solution {
private:
    unordered_map<string, vector<pair<string, double>>> g; // "string": (string, dist)
    unordered_set<string> st;
    double dfs(string u, string v) {
        double ret = -1;
        double temp;
        if (u == v) {
            return 1;
        }
        if (g.find(u) != g.end()) {
            for (auto& p : g[u]) {
                if (st.find(p.first) != st.end())
                    continue;
                st.insert(p.first);
                temp = dfs(p.first, v);
                if (temp != -1) {
                    ret = p.second * temp;
                }
            }
        }
        return ret;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        int e_size = values.size(); // numbers of edge

        for (int i = 0; i < e_size; i++) {
            g[equations[i][0]].emplace_back(pair{equations[i][1], values[i]});
            g[equations[i][1]].emplace_back(pair{equations[i][0], 1 / values[i]});
        }
        for (auto const&q : queries) {
            if (g.find(q[0]) == g.end() || g.find(q[1]) == g.end()) {
                ans.emplace_back(-1.0);
            } else {
                st.insert(q[0]);
                ans.emplace_back(dfs(q[0], q[1]));
                st.clear();
            }
        }
        return ans;
    }
};

