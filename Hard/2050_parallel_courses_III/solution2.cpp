/**
 * Title:  Parallel Courses III (Leetcode Hard 2050)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, October, 2023
 * Method: Add indegree == 0's node in queue and use maxTime to record the cost of each node. The answer is the max of all (start) node cost.
 * Result: Time complexity O(E + V), Space complexity O(V + E)
 */

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n + 1);
        vector<int> indegree(n + 1);

        for (auto& relation: relations) {
            graph[relation[0]].emplace_back(relation[1]);
            indegree[relation[1]]++;
        }

        vector<int> maxTime(n + 1, 0);
        queue<int> q;

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                maxTime[i] = time[i - 1];
            }
        }
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& v: graph[node]) {
                maxTime[v] = max(maxTime[v], maxTime[node] + time[v - 1]);
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            ans = max(ans, maxTime[i]);
        return ans;
    }
};
