/**
 * Title:  Special Array II (Leetcode Medium 3152)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   09, December, 2024
 * Method: Store the valid range into v. Use binary search to find the left range or right range to check whether the query range is valid.
 * Result: Time complexity is O(n + mlogn), space complexity is O(n).
 */

class Solution {
public:
    void print(const vector<pair<int, int>>& v) {
        for (const auto& p: v) {
            cout << "(" << p.first << "," << p.second << ") ";
        }
        cout << "\n";
    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<pair<int, int>> v;
        int start = 0;
        for (int i = 1; i < n; i++) {
            if (!((nums[i] ^ nums[i - 1]) & 1)) { // break parity
                if (start < i - 1) {
                    v.emplace_back(make_pair(start, i - 1));
                }
                start = i;
            }
        }
        if (start < n - 1)
            v.emplace_back(make_pair(start, n - 1));
        print(v);
        int v_size = v.size();
        function<int(int)> bs_left = [&](int x) { // find the range whose left side is equals x
            int l = 0, r = v_size;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (v[mid].first == x) {
                    return mid;
                } else if (v[mid].first < x) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return l;
        };

        function<int(int)> bs_right = [&](int x) { // find the range whose right side is equals x
            int l = 0, r = v_size;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (v[mid].second == x) {
                    return mid;
                } else if (v[mid].second < x) {
                    l = mid + 1;
                } else {
                    r = mid;
                }
            }
            return l;
        };

        vector<bool> ans(m, false);
        
        for (int i = 0; i < m; i++) {
            if (queries[i][0] == queries[i][1]) {
                ans[i] = true;
                continue;
            } else if (v_size == 0) {
                continue;
            }
            int id = bs_left(queries[i][0]);
            // cout << i << ": " << id << "\n";
            if (id < v_size && v[id].first <= queries[i][0] && v[id].second >= queries[i][1]) {
                ans[i] = true;
            }
            id = bs_right(queries[i][1]);
            // cout << i << ": " << id << "\n";
            if (id < v_size && v[id].first <= queries[i][0] && v[id].second >= queries[i][1]) {
                ans[i] = true;
            }
        }
        return ans;
    }
};


// 3 4 1 2 6
// 1 0 1 0 0
// 1 1 0 0 0

// 4 3 1 6
// 0 1 1 0
// 0 1 0 0
// 0