/**
 * Title:  Valid Arrangement of Pairs (Leetcode Hard 2097)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, November, 2024
 * Method: Use stack to implement iterative DFS to find the order of nodes in post order. The start node is the node that has outdegree = indegree + 1. If there is no such node, we can start from the first node in the pairs.
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
        
        // 3. Find path
        vector<int> result;
        stack<int> st;
        st.push(head);
        
        // Iterative DFS using stack
        while (!st.empty()) {
            int node = st.top();
            if (!graph[node].empty()) {
                // visit next node
                int nxt = graph[node].back();
                graph[node].pop_back();
                st.push(nxt);
            } else { // no edge
                result.emplace_back(node);
                st.pop();
            }
        }

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