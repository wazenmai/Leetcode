/**
 * Title:  Course Schedule (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, July, 2023
 */

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);
        for (auto r: prerequisites) {
            inDegree[r[0]]++;
            graph[r[1]].emplace_back(r[0]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        int visit = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visit++;
            // traverse its children
            for (int v: graph[u]) {
                --inDegree[v];
                if (inDegree[v] == 0)
                    q.push(v);
            }
        }
        if (visit == numCourses)
            return true;
        return false;
    }
};
