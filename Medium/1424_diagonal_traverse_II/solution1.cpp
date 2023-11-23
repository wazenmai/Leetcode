/**
 * Title:  Diagonal Traverse II (Leetcode Medium 1424)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, November, 2023
 * Method: It can be sort by the sum of (row, col). Here use this sum as the map's key,
    *  and when iterate the map, we need to first sort the vector by the row of the number.
 * Result: Time complexity: O(nlogn), Space complexity: O(n)
 */

class Solution {
public:
    void print(vector<int>& v) {
        for (auto& e: v) {
            cout << e << " ";
        }
        cout << "\n";
    }
    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        map<int, vector<pair<int, int>>> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                m[i + j].emplace_back(make_pair(i, nums[i][j]));
            }
        }
        vector<int> ans;
        for (auto it = m.begin(); it != m.end(); it++) {
            sort(it->second.begin(), it->second.end(), compare);
            for (auto& e: it->second) {
                ans.emplace_back(e.second);
            }
        }
        return ans;
    }
};

// (0, 0) = 0
// (1, 0) = 1
// (0, 1) = 1
// (2, 0) = 2
// (1, 1) = 2
// (0, 2) = 2
