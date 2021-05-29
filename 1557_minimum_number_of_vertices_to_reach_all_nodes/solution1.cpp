/**
 * Title:  Minimum Number of Vertices to Reach All Nodes (Leetcode Medium 1557)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, May, 2021
 * Method: Graph, Indegree
 */

class Solution {
private:
    vector<int> indegree;
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        indegree.resize(n, 0);
        for (auto& e : edges) {
            indegree[e[1]]++;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                ans.emplace_back(i);
        }
        return ans;
    }
};
