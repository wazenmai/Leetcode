/**
 * Title:  Maximum Number of K-Divisible Components (Leetcode Hard 2872)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, December, 2024
 * Method: DFS. Since the whole tree is connected and is valid initially, so if there is a subtree that is divisible by k, the rest of the tree is still valid.
 * Result: Time complexity O(n + m), Space complexity O(n). m is the number of edges.
 */

class Solution {
private:
    void print(const vector<int>& v) {
        for (auto& e: v) {
            cout << e << ",";
        }
        cout << "\n";
    }
public:
    int maxKDivisibleComponents(const int n, const vector<vector<int>>& edges, const vector<int>& values, const int k) {
        vector<vector<int>> graph(n);
        for (const auto& e: edges) {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }
        int ans = 1;
        vector<bool> visit(n, false);
        function<long long(int)> get_sum = [&](int i) {
            queue<int> q;
            for (const auto& v: graph[i]) {
                if (visit[v]) continue;
                q.push(v);
                visit[v] = true;
            }
            long long s = values[i];
            while (!q.empty()) {
                auto u = q.front();
                long long subtree_sum = get_sum(u);
                if (subtree_sum % k == 0) {
                    ans++;
                } else {
                    s += subtree_sum;
                }
                q.pop();
            }
            return s;
        };
        visit[0] = true;
        get_sum(0);
        return ans;
    }
};
