/**
 * Title:  Divide Intervals Into Minimum Number of Groups (Leetcode Medium 2406)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, October, 2024
 * Method: When we step in an interval start, overlap section + 1. When we step out an interval end, overlap section - 1. The maximum overlap section is the minimum number of groups.
 * Result: O(nlogn). Space complexity O(n).
 */

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> v;
        for (auto& interval: intervals) {
            v.emplace_back(make_pair(interval[0], 1)); // when we step in interval, overlap + 1
            v.emplace_back(make_pair(interval[1] + 1, -1)); // when we step out interval, overlap - 1
        }
        sort(v.begin(), v.end());
        int ans = 0;
        int x = 0;
        for (auto& p: v) {
            x += p.second;
            ans = max(ans, x);
        }
        return ans;
    }
};
