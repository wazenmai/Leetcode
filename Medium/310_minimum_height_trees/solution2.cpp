/**
 * Title:  Minimum Height Trees (Leetcode Medium 310)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, Dec, 2021
 * Method: Find center of the tree, keep deleting leaf nodes O(V+E)
 * Result: Accepted
 */

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            vector<int> ans{0};
            return ans;
        } else if (n == 2) {
            vector<int> ans{0, 1};
            return ans;
        }
        
        vector<int> neighbor[n];
        vector<int> indegree(n, 0);
        for (auto edge: edges) {
            neighbor[edge[0]].emplace_back(edge[1]);
            neighbor[edge[1]].emplace_back(edge[0]);
            ++indegree[edge[0]];
            ++indegree[edge[1]];
        }
        
        vector<int> ans;
        queue<int> q;
        vector<bool> visit(n, false);
        
        // we want to find the center of the tree
        // so we start from indegree = 1's node (leaf)
        // and we delete them, then restart from indegree = 1
        // so the last nodes will be the root of MHT
        for (int i = 0; i < n; i++){
            if (indegree[i] == 1) {
                q.push(i);
                visit[i] = true;
                --indegree[i];
            }
        }
        
        int sz = q.size();
        
        while (!q.empty()) {
            auto v = q.front();
            ans.emplace_back(v);
            q.pop();
            --sz;
            
            for (auto& nb: neighbor[v]) {
                if (!visit[nb]) {
                    --indegree[nb];
                    if (indegree[nb] == 1) {
                        q.push(nb);
                        visit[nb] = true;
                    }
                }
            }
            
            if (sz == 0) {
                if (!q.empty())
                    ans.clear();
                sz = q.size();
            }
        }
        return ans;
    }
};