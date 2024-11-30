/**
 * Title:  Valid Arrangement of Pairs (Leetcode Hard 2097)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, November, 2024
 * Method: View pairs as directed edges, our goal is to find a euler path that visits every edge exactly once. We can use postorder DFS to find the order of nodes.
 * Result: Time complexity is O(V + E). Space complexity is O(V + E).
 */

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        unordered_map<int, int> indegree;
        unordered_map<int, int> outdegree;
        unordered_map<int, vector<int>> graph;
        
        // 1. Construct graph + record indegree, outdegree
        for (auto& p: pairs) {
            int st = p[0], ed = p[1];
            indegree[ed]++;
            outdegree[st]++;
            graph[st].emplace_back(ed);
        }
        
        vector<int> result;

        function<void(int)> dfs = [&](int node) { // record the order of node in post order
            while (!graph[node].empty()) {
                int nxt = graph[node].back();
                graph[node].pop_back();
                dfs(nxt);
            }
            // add node after processed all its edges
            result.emplace_back(node);
        };

        // 2. Find start node
        int head = -1;
        for (const auto& entry: outdegree) {
            int node = entry.first;
            if (outdegree[node] == indegree[node] + 1) {
                head = node;
                break;
            }
        }
        if (head == -1) {
            head = pairs[0][0];
        }
        
        // 3. start dfs
        dfs(head);
        reverse(result.begin(), result.end());
        vector<vector<int>> ans;
        for (int i = 1; i < result.size(); i++) {
            ans.emplace_back(vector<int>{result[i - 1], result[i]});
        }
        return ans;
    }
};

// euler path: visit every edge at once
    // directed graph:
        // each node's outdegree = indegree
        // exactly one node has outdegree = indegree + 1
// start: out > in
