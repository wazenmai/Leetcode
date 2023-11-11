/**
 * Title:  Design Graph With Shortest Path Calculator (Leetcode Hard 2642)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, November, 2023
 * Method: Dijkstra's algorithm
 */

class Graph {
private:
    vector<vector<pair<int, int>>> g; // dst, weight
    int v;
    void printgraph(vector<vector<pair<int, int>>>& g) {
        for (int i = 0; i < g.size(); i++) {
            cout << i << ": ";
            for (auto e: g[i]) {
                cout << "(" << e.first << "," << e.second << ") ";
            }
            cout << "\n";
        }
    }
public:
    Graph(int n, vector<vector<int>>& edges) {
        v = n;
        g.resize(n);
        for (auto& e: edges) {
            g[e[0]].emplace_back(make_pair(e[1], e[2])); // (node, weight)
        }
        // printgraph(g);
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]].emplace_back(make_pair(edge[1], edge[2]));
    }
    
    int shortestPath(int node1, int node2) {
        // cout << "---sortestPath--- " << node1 << "->" << node2 << "\n";
        vector<int> dist(v, 1e9);
        vector<bool> visit(v, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // dist, node
        pq.push(make_pair(0, node1));
        dist[node1] = 0;
        int visited = 0;
        while (visited < v && !pq.empty()) {
            int cur_node = pq.top().second;
            int cur_dist = pq.top().first;
            pq.pop();
            // cout << visited << ", " << cur_node << ", " << cur_dist << "\n"; 
            if (visit[cur_node]) continue;
            visit[cur_node] = true;
            visited++;
            for (auto node: g[cur_node]) {
                if (visit[node.first]) continue;
                if (cur_dist + node.second < dist[node.first]) {
                    // cout << node.first << ": org " << dist[node.first] << ", new " << cur_dist + node.second << "\n";
                    dist[node.first] = cur_dist + node.second;
                    pq.push(make_pair(dist[node.first], node.first));
                    // cout << "push " << node.first << ", " << dist[node.first] << "\n";
                }
            }
        }
        if (dist[node2] == 1e9) return -1;
        return dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */