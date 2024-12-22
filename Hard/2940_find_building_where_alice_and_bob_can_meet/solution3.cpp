/**
 * Title:  Find Building Where Alice and Bob Can Meet (Leetcode Medium 1497)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, December, 2024
 * Method: Optimization of solution2.cpp
 * Result: Time complexity O(mlogn). Space complexity O(n + m). m is the number of queries, n is the number of buildings. 
 */

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), m = queries.size();
        vector<int> ans(m, -1);
        // Step 1. Process query
        vector<vector<pair<int, int>>> new_q(n); // height_id: (query max height, query_id)
        for (int i = 0; i < m; i++) { // iterate queries
            int a = queries[i][0];
            int b = queries[i][1];
            if (a == b) {
                ans[i] = a;
            } else if (a < b && heights[a] < heights[b]) {
                ans[i] = b;
            } else if (a > b && heights[a] > heights[b]) {
                ans[i] = a;
            } else {
                new_q[max(a, b)].emplace_back(make_pair(max(heights[a], heights[b]), i));
            }
        }
        
        // Step 2. Form monotonic stack and iterate query from heights id big to small
        vector<pair<int, int>> mono; // (heights, id). from left to right, heights and id decreasing
        for (int i = n - 1; i >= 0; i--) {
            while (!mono.empty() && heights[i] >= mono.back().first) {
                mono.pop_back();
            }
            mono.emplace_back(make_pair(heights[i], i));
            for (auto& q: new_q[i]) {
                auto it = lower_bound(mono.rbegin(), mono.rend(), pair{q.first + 1, 0});
                if (it != mono.rend()) {
                    ans[q.second] = it->second;
                }
            }
        }
        return ans;
    }
};

// 1. process query: only leave the rightmost query index i, we need to find index j that j > i and heights[j] > heights[i].
// 2. sort query: let the index from left to right is small to big index
// 3. from biggest index query, we want to know leftmost id that height[id] > height[q].
    // - we can maintain a right to left decreasing number array (monotonic), 
    // ex: 9 12 10, we don't need 10 since 12 is lefter and bigger heights, any index that < 12's index will choose 12 but not 10. so the monotonic array would be [9, 12].
    // ex: [9 12 1 2 3], it will left [9, 12]

// Optimization
// 1. deque -> vector
// 2. vector<int> (id) -> vector<pair<int, int>> (height, id)
// 3. change the way to store query
