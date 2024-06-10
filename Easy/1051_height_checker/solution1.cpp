/**
 * Title:  Height Checker (Leetcode Easy 1051)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, June, 2024
 */

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> ordered;
        ordered = heights;
        sort(ordered.begin(), ordered.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (heights[i] != ordered[i])
                ans++;
        }
        return ans;
    }
};
