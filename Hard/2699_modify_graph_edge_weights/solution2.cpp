/**
 * Title:  Modify Graph Edge Weights (Leetcode Hard 2699)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, August, 2024
 * Method: Since solution1.cpp needs to run dijkstra for multiple times. Here we modify it to only run two times.
 *         1. Calculate shortest path viewing -1 edge as 1. If the shortest path from source to destination is greater than target, we can't even meet target with smallest modified weight, return empty vector.
 *         2. Calculate shortest path viewing -1 edge as the difference between target -  shortest path in first run + the shortest path from source to nxt (v) (from first run) - the path we have walked through in this run (source ~ u). u -> v
 *         If the shortest path from source to destination is less than target, meaning there is a shorter path (than target) to destination, return empty vector.
 *         Else, we meet the target and mark rest of -1 edges to 1 to stay same with first run.
 * Result: Time compleixty is O((n + m)logn) for Dijkstra, so the total time complexity is O(2(n + m)logn) = O(mlogn) // m usually >> n. Space compleixty is O(2m + 2n) for graph and distances, O(n + m) for Dijkstra.
 */

class Solution {
public:
    void dijkstra(const vector<vector<pair<int, int>>>& graph, vector<vector<int>>& edges, vector<vector<int>>& distances, int source, int difference, int run) {
        int n = graph.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, source));
        distances[source][run] = 0;

        while (!pq.empty()) {
            auto [dist, cur] = pq.top();
            pq.pop();

            if (dist > distances[cur][run]) continue;

            for (auto& neighbor: graph[cur]) {
                int nxt = neighbor.first;
                int ei = neighbor.second;
                int weight = edges[ei][2];
                if (weight == -1) weight = 1;
                if (run == 1 && edges[ei][2] == -1) {
                    // diff btw. shortest-path and target + existed dist - the dist we already walk through = new dist of this edge!
                    int new_weight = difference + distances[nxt][0] - distances[cur][1];
                    if (new_weight > weight) {
                        edges[ei][2] = weight = new_weight;
                    }
                }
                if (distances[nxt][run] > distances[cur][run] + weight) {
                    distances[nxt][run] = distances[cur][run] + weight;
                    pq.push(make_pair(distances[nxt][run], nxt));
                }
            }
        }
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        int m = edges.size();
        vector<vector<pair<int, int>>> graph(n);
        for (int i = 0; i < m; i++) {
            graph[edges[i][0]].emplace_back(make_pair(edges[i][1], i));
            graph[edges[i][1]].emplace_back(make_pair(edges[i][0], i));
        }

        vector<vector<int>> distances(n, vector<int>(2, INT_MAX));
        distances[source][0] = distances[source][1] = 0;
        // 1. Find shortest path with replacing -1 edge to 1
        dijkstra(graph, edges, distances, source, 0, 0);
        // 1.1 Calculate the difference of dist(cur-shortest-path) and target
        int difference = target - distances[destination][0]; 
        // 1.2 If shortest path dist > target, we can't meet target even with smallest modified weight
        if (difference < 0) return vector<vector<int>>{};
        
        // 2. Adjust -1 edge to meet target
        dijkstra(graph, edges, distances, source, difference, 1);
        // 2.1 Even if we modify edge to meet target, there's still a shorter path to dest
        if (distances[destination][1] < target) return vector<vector<int>>{};
        
        for (auto& e: edges) {
            if (e[2] == -1) e[2] = 1;
        }
        return edges;
    }
};
