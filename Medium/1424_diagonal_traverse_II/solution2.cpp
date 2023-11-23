/**
 * Title:  Diagonal Traverse II (Leetcode Medium 1424)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, November, 2023
 * Method: Since C++ map will sort the key automatically, but our number is continuous, so we can remember the max sum and use unordered_map.
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
        int maxsum = 0;
        unordered_map<int, vector<pair<int, int>>> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                m[i + j].emplace_back(make_pair(i, nums[i][j]));
                maxsum = max(maxsum, i + j);
            }
        }
        vector<int> ans;
        for (int i = 0; i <= maxsum; i++) {
            sort(m[i].begin(), m[i].end(), compare);
            for (auto& e: m[i]) {
                ans.emplace_back(e.second);
            }
        }
        return ans;
    }
};
