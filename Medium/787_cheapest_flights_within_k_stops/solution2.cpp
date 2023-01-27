/**
 * Title:  Cheapest Flights Within K Stops (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, Janurary, 2023
 * Method: Bellman Ford
 */

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX); // distance from source to all other nodes
        dist[src] = 0;

        // Run K+1 times to relax the edge
        for (int i = 0; i <= k; i++) {
            vector<int> temp(dist);
            for (auto& flight: flights) {
                if (dist[flight[0]] != INT_MAX) {
                    temp[flight[1]] = min(temp[flight[1]], dist[flight[0]] + flight[2]);
                }
            }
            dist = temp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
