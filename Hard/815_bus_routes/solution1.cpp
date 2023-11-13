/**
 * Title:  Bus Routes (Leetcode Hard 815)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, November, 2023
 * Method: Use dist to record the distance from source to each stop. Iterate through every route until no need to update dist.
 * Result: Time complexity: O(n^2m) = 5e7. n = # of routes, m = average # of stops in each routes. n <= 500, nm <= 1e5.
 */

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        // Get maxStop
        int maxStop = 0;
        for (const auto& route: routes) {
            for (const int& stop: route) {
                maxStop = max(maxStop, stop);
            }
        }

        // If target is not in route, return -1
        if (maxStop < target) return -1;

        // Construct Distance Array
        vector<int> dist(maxStop + 1, 1e9);
        
        // Iterate all route to update distance array
        dist[source] = 0;
        bool flag = true;
        int n = routes.size();
        while (flag) {
            // cout << "loop\n";
            flag = false;
            int i = 0;
            for (const auto& route: routes) {
                i++;
                int min_dist = n + 1;
                for (int stop: route) {
                    min_dist = min(min_dist, dist[stop]);
                }
                min_dist++;
                for (int stop: route) {
                    if (dist[stop] > min_dist) {
                        dist[stop] = min_dist;
                        flag = true;
                    }
                }
            }
        }
        
        if (dist[target] >= n + 1) return -1;
        return dist[target];
    }
};
