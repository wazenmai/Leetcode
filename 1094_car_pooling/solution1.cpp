/**
 * Title:  Car Pooling (Leetcode Medium 1094)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, Jan, 2022
 * Method: O(n)
 */

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> new_trip;
        for (auto& t: trips) {
            new_trip.emplace_back(t[1], t[0]);
            new_trip.emplace_back(t[2], -t[0]);
        }
        sort(new_trip.begin(), new_trip.end());
        
        int passenger = 0;
        for (auto& t: new_trip) {
            passenger += t.second;
            if (passenger > capacity)
                return false;
        }
        return true;
    }
};
