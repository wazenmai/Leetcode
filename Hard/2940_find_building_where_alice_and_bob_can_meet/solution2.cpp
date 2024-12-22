/**
 * Title:  Find Building Where Alice and Bob Can Meet (Leetcode Medium 1497)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, December, 2024
 * Method: Process query and use monotonic stack. Please refer to the code comments for more details.
 * Result: Time complexity O(m + mlogm + mlogn) = O(mlog(n + m)). Space complexity O(n + m). m is the number of queries, n is the number of buildings. 
 */

class Solution {
public:
    void print(deque<int>& dq) {
        for (auto& e: dq) {
            cout << e << ",";
        }
        cout << "\n";
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size(), m = queries.size();
        vector<int> ans(m, -1);
        // Step 1. Process query
        vector<vector<int>> new_q; // large index, large height, query_id
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
                new_q.emplace_back(vector<int>{max(a, b), max(heights[a], heights[b]), i});
            }
        }
        // Step 2. Sort query
        sort(new_q.begin(), new_q.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        }); // new_q: large index -> small index

        // Step 3. Form monotonic stack
        deque<int> mono; // heights id that form monotonic stack, from left to right the id is bigger and the heights is bigger too
        
        function<int(int)> binary_search = [&](int value) {
            int l = 0, r = mono.size();
            while (l < r) {
                int mid = (l + r) >> 1;
                if (heights[mono[mid]] <= value) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return l;
        };
        mono.push_back(n - 1);
        int process_index = n - 1;
        for (auto& q: new_q) {
            int id = q[0], h = q[1], ans_id = q[2];
            // cout << "query: " << id << ", " << h << ", " << ans_id << ": ";
            if (id + 1 < process_index) {
                for (int i = process_index - 1; i > id; i--) {
                    while (!mono.empty() && heights[i] >= heights[mono.front()]) {
                        mono.pop_front();
                    }
                    mono.push_front(i);
                }
                process_index = id + 1;
            }
            int mono_id = binary_search(h);
            // cout << mono_id << "\n";
            // print(mono);
            if (mono_id < mono.size())
                ans[ans_id] = mono[mono_id];
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
