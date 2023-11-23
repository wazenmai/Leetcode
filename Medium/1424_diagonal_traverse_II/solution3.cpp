/**
 * Title:  Diagonal Traverse II (Leetcode Medium 1424)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, November, 2023
 * Method: If the start point is (0, 0), the traverse order is the bfs of first go down than go right.
 * Result: Time complexity: O(n), Space complexity: O(n)
 */

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0)); // (row, col)
        vector<int> ans;

        while (!q.empty()) {
            auto cur = q.front();
            ans.emplace_back(nums[cur.first][cur.second]);
            // cout << cur.first << ", " << cur.second << "\n";
            q.pop();

            if (cur.second == 0 && cur.first < n - 1) {
                q.push(make_pair(cur.first + 1, cur.second));
            }

            if (cur.second < nums[cur.first].size() - 1) {
                q.push(make_pair(cur.first, cur.second + 1));
            }
        }
        return ans;
    }
};
